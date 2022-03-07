// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:04)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H

#include "DistanceTest.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::DistanceTest<Real, Vector>::DistanceTest(const Vector& lhs, const Vector& rhs) noexcept
    : ParentType{}, m_Lhs{ lhs }, m_Rhs{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

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

    auto distanceSquared = Vector::ToolsType::DistanceSquared(m_Lhs, m_Rhs);

    return DistanceResult{ distanceSquared, Real{}, m_Lhs, m_Rhs };
}

template <typename Real, typename Vector>
typename Mathematics::DistanceTest<Real, Vector>::DistanceResult Mathematics::DistanceTest<Real, Vector>::GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto lhsClosestPoint = m_Lhs.GetMove(t, lhsVelocity);
    auto rhsClosestPoint = m_Rhs.GetMove(t, rhsVelocity);

    auto distanceSquared = Vector::ToolsType::DistanceSquared(lhsClosestPoint, rhsClosestPoint);

    return DistanceResult{ distanceSquared, t, lhsClosestPoint, rhsClosestPoint };
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceTest<Real, Vector>::GetLhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Lhs;
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceTest<Real, Vector>::GetRhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rhs;
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TEST_DETAIL_H
