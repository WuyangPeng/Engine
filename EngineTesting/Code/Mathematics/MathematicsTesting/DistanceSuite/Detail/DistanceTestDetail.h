///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:30)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H

#include "DistanceTest.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceTest<Real, Vector>::DistanceTest(const Vector& lhs, const Vector& rhs) noexcept
    : ParentType{}, lhs{ lhs }, rhs{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::DistanceTest<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
typename Mathematics::DistanceTest<Real, Vector>::DistanceResult Mathematics::DistanceTest<Real, Vector>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto distanceSquared = Vector::ToolsType::DistanceSquared(lhs, rhs);

    return DistanceResult{ distanceSquared, Real{}, lhs, rhs };
}

template <typename Real, typename Vector>
typename Mathematics::DistanceTest<Real, Vector>::DistanceResult Mathematics::DistanceTest<Real, Vector>::GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsClosestPoint = lhs.GetMove(t, lhsVelocity);
    const auto rhsClosestPoint = rhs.GetMove(t, rhsVelocity);

    auto distanceSquared = Vector::ToolsType::DistanceSquared(lhsClosestPoint, rhsClosestPoint);

    return DistanceResult{ distanceSquared, t, lhsClosestPoint, rhsClosestPoint };
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceTest<Real, Vector>::GetLhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhs;
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceTest<Real, Vector>::GetRhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhs;
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H
