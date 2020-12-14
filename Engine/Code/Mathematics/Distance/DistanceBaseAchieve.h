///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/07 15:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H

#include "DistanceBase.h"
#include "DistanceResultDetail.h"
#include "Detail/IntervalDistanceDetail.h"
#include "Detail/IntervalDistanceSquaredDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename Vector>
Mathematics::DistanceBase<Real, Vector>::DistanceBase() noexcept
    : m_MaximumIterations{ sm_DefaultMaximumIterations },
      m_ZeroThreshold{ sm_DefaultZeroThreshold },
      m_DifferenceStep{ sm_DefaultDifferenceStep },
      m_InverseTwoDifferenceStep{ Math::GetRational(1, 2) / m_DifferenceStep }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceBase<Real, Vector>::IsValid() const noexcept
{
    try
    {
        if (0 < m_MaximumIterations && Math::GetValue(0) <= m_ZeroThreshold && Math::GetValue(0) < m_DifferenceStep &&
            Math::Approximate(Math::GetRational(1, 2) / m_DifferenceStep, m_InverseTwoDifferenceStep, m_ZeroThreshold))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>::SetDifferenceStep(Real differenceStep) noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) < differenceStep, "��Ч������ֵ\n");

    m_DifferenceStep = differenceStep;
    m_InverseTwoDifferenceStep = Math::GetRational(1, 2) / m_DifferenceStep;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDifferenceStep() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DifferenceStep;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>::SetMaximumIterations(int maximumIterations) noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(0 < maximumIterations, "��Ч������������\n");

    m_MaximumIterations = maximumIterations;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>::SetZeroThreshold(Real zeroThreshold) noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= zeroThreshold, "��Ч���ٽ�ֵ\n");

    m_ZeroThreshold = zeroThreshold;
}

template <typename Real, typename Vector>
int Mathematics::DistanceBase<Real, Vector>::GetMaximumIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaximumIterations;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetZeroThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ZeroThreshold;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::Get() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = GetSquared();
    result.SetSqrtDistance();

    return result;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = GetSquared(t, lhsVelocity, rhsVelocity);
    result.SetSqrtDistance();

    return result;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ʹ�����޲�ֽ��ƣ� f'(t) = (f(t + h) - f(t - h))/(2 * h)
    auto funcPlus = Get(t + m_DifferenceStep, lhsVelocity, rhsVelocity);
    auto funcMinus = Get(t - m_DifferenceStep, lhsVelocity, rhsVelocity);
    auto derivativeApproximation = m_InverseTwoDifferenceStep * (funcPlus.GetDistance() - funcMinus.GetDistance());

    return derivativeApproximation;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // �������ƽ������ĵ���Ϊ�ض�������ķ�����������Ӧ����д����
    auto distance = Get(t, lhsVelocity, rhsVelocity);
    auto derivative = GetDerivative(t, lhsVelocity, rhsVelocity);

    return Math::GetValue(2) * distance.GetDistance() * derivative;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ����ļ����ǣ�����f(t)��һ��͹������
    // f'(tmin) >= 0������С������tmin����f'(tmax) <= 0������С������tmax��
    // ����f'(0) < 0��f'(tmax) > 0 ����С������(tmin,tmax)��һЩt��

    IntervalDistance<Real, Vector> intervalDistance{ *this, tMin, tMax, lhsVelocity, rhsVelocity };

    return intervalDistance.GetResult();
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ����ļ����ǣ�����f(t)��һ��͹������
    // f'(tmin) >= 0������С������tmin����f'(tmax) <= 0������С������tmax��
    // ����f'(0) < 0��f'(tmax) > 0 ����С������(tmin,tmax)��һЩt��

    IntervalDistanceSquared<Real, Vector> intervalDistanceSquared{ *this, tMin, tMax, lhsVelocity, rhsVelocity };

    return intervalDistanceSquared.GetResult();
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H
