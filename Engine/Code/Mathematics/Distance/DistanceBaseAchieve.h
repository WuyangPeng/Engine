///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/19 22:14)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H

#include "DistanceBase.h"
#include "DistanceResultDetail.h"
#include "Detail/IntervalDistanceDetail.h"
#include "Detail/IntervalDistanceSquaredDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename Vector>
Mathematics::DistanceBase<Real, Vector>::DistanceBase() noexcept
    : maximumIterations{ defaultMaximumIterations },
      zeroThreshold{ defaultZeroThreshold },
      differenceStep{ defaultDifferenceStep },
      inverseTwoDifferenceStep{ Math::GetRational(1, 2) / differenceStep }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceBase<Real, Vector>::IsValid() const noexcept
{
    try
    {
        if (0 < maximumIterations &&
            Math::GetValue(0) <= zeroThreshold &&
            Math::GetValue(0) < differenceStep &&
            Math::Approximate(Math::GetRational(1, 2) / differenceStep, inverseTwoDifferenceStep, zeroThreshold))
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
void Mathematics::DistanceBase<Real, Vector>::SetDifferenceStep(Real newDifferenceStep) noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) < newDifferenceStep, "��Ч������ֵ\n");

    differenceStep = newDifferenceStep;
    inverseTwoDifferenceStep = Math::GetRational(1, 2) / differenceStep;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDifferenceStep() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return differenceStep;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>::SetMaximumIterations(int newMaximumIterations) noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(0 < newMaximumIterations, "��Ч������������\n");

    maximumIterations = newMaximumIterations;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>::SetZeroThreshold(Real newZeroThreshold) noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= newZeroThreshold, "��Ч���ٽ�ֵ\n");

    zeroThreshold = newZeroThreshold;
}

template <typename Real, typename Vector>
int Mathematics::DistanceBase<Real, Vector>::GetMaximumIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maximumIterations;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetZeroThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return zeroThreshold;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::Get() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = GetSquared();
    result.SetSqrtDistance(result.GetDistance());

    return result;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = GetSquared(t, lhsVelocity, rhsVelocity);
    result.SetSqrtDistance(result.GetDistance());

    return result;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ʹ�����޲�ֽ��ƣ� f'(t) = (f(t + h) - f(t - h))/(2 * h)
    const auto funcPlus = Get(t + differenceStep, lhsVelocity, rhsVelocity);
    const auto funcMinus = Get(t - differenceStep, lhsVelocity, rhsVelocity);
    const auto derivativeApproximation = inverseTwoDifferenceStep * (funcPlus.GetDistance() - funcMinus.GetDistance());
 
    return derivativeApproximation;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>::GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // �������ƽ������ĵ���Ϊ�ض�������ķ�����������Ӧ����д����
    const auto distance = Get(t, lhsVelocity, rhsVelocity);
    const auto derivative = GetDerivative(t, lhsVelocity, rhsVelocity);

    return Math::GetValue(2) * distance.GetDistance() * derivative;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ����ļ����ǣ�����f(t)��һ��͹������
    // f'(tmin) >= 0������С������tmin����f'(tmax) <= 0������С������tmax��
    // ����f'(0) < 0��f'(tmax) > 0 ����С������(tmin,tmax)��һЩt��

    IntervalDistance<Real, Vector> intervalDistance{ *this, tMin, tMax, lhsVelocity, rhsVelocity };

    return intervalDistance.GetResult();
}

template <typename Real, typename Vector>
typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>::GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // ����ļ����ǣ�����f(t)��һ��͹������
    // f'(tmin) >= 0������С������tmin����f'(tmax) <= 0������С������tmax��
    // ����f'(0) < 0��f'(tmax) > 0 ����С������(tmin,tmax)��һЩt��

    IntervalDistanceSquared<Real, Vector> intervalDistanceSquared{ *this, tMin, tMax, lhsVelocity, rhsVelocity };

    return intervalDistanceSquared.GetResult();
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_ACHIEVE_H
