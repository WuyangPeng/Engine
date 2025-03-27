///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 15:14)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H

#include "IntervalDistanceBase.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"

template <typename Real, typename Vector>
Mathematics::IntervalDistanceBase<Real, Vector>::IntervalDistanceBase(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity)
    : distance{ distance },
      tMin{ tMin },
      tMax{ tMax },
      lhsVelocity{ lhsVelocity },
      rhsVelocity{ rhsVelocity },
      distanceResult{ MathType::GetValue(0) },
      beginT{ tMin },
      endT{ tMax },
      beginDistanceResult{ MathType::GetValue(0) },
      beginDerivativeDistanceResult{ MathType::GetValue(0) },
      endDistanceResult{ MathType::GetValue(0) },
      endDerivativeDistanceResult{ MathType::GetValue(0) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
void Mathematics::IntervalDistanceBase<Real, Vector>::Solve()
{
    // ����ļ����ǣ�����f(t)��һ��͹������
    // f'(tmin) >= 0������С������tmin����f'(tmax) <= 0������С������tmax��
    // ����f'(0) < 0��f'(tmax) > 0 ����С������(tmin,tmax)��һЩt��
    if (!(CheckBeginMonotonicFunction() || CheckEndMonotonicFunction()))
    {
        if (!Iteration())
        {
            BisectionMethod();
        }
    }
}

template <typename Real, typename Vector>
typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>::GetDistanceResult(Real t) const
{
    return distance.Get(t, lhsVelocity, rhsVelocity);
}

template <typename Real, typename Vector>
typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>::GetDistanceResultSquared(Real t) const
{
    return distance.GetSquared(t, lhsVelocity, rhsVelocity);
}

template <typename Real, typename Vector>
Real Mathematics::IntervalDistanceBase<Real, Vector>::GetDerivativeDistanceResult(Real t) const
{
    return distance.GetDerivative(t, lhsVelocity, rhsVelocity);
}

template <typename Real, typename Vector>
Real Mathematics::IntervalDistanceBase<Real, Vector>::GetDerivativeDistanceResultSquared(Real t) const
{
    return distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);
}

template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>::CheckBeginMonotonicFunction()
{
    beginDistanceResult = Get(beginT);
    if (beginDistanceResult.GetDistance() <= distance.GetZeroThreshold())
    {
        // ����Ϊ��Чֵ�㡣�����������λ�ýӴ���
        beginDistanceResult.Set(MathType::GetValue(0), beginT);
        distanceResult = beginDistanceResult;

        return true;
    }

    beginDerivativeDistanceResult = GetDerivative(beginT);
    if (MathType::GetValue(0) <= beginDerivativeDistanceResult)
    {
        // ������[0,tmax]���ӡ�
        beginDistanceResult.SetContactTime(beginT);
        distanceResult = beginDistanceResult;

        return true;
    }

    return false;
}

template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>::CheckEndMonotonicFunction()
{
    endDistanceResult = Get(endT);
    if (endDistanceResult.GetDistance() <= distance.GetZeroThreshold())
    {
        // ����Ϊ��Чֵ�㡣
        endDistanceResult.Set(MathType::GetValue(0), endT);
        distanceResult = endDistanceResult;

        return true;
    }

    endDerivativeDistanceResult = GetDerivative(endT);
    if (endDerivativeDistanceResult <= MathType::GetValue(0))
    {
        // ������[0,tmax]���ӡ�
        endDistanceResult.SetContactTime(endT);
        distanceResult = endDistanceResult;

        return true;
    }

    return false;
}

template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>::Iteration()
{
    // ��ʼ��ţ�ٷ�������㵱����Ϊ���ʱ�䡣
    // �ڴ˹����У��������ȷ���þ��벻��Ϊ�㣬���ǽ��л���һ����С��ֵ��
    const auto maximumIterations = distance.GetMaximumIterations();
    for (auto loop = 0; loop < maximumIterations; ++loop)
    {
        // ������һ��ţ�ٵ���
        auto iterationT = beginT - beginDistanceResult.GetDistance() / beginDerivativeDistanceResult;
        if (tMax <= iterationT)
        {
            // ͼ�ε�͹�Ա�֤������������ʱ��������Ϊ�����л�����С���֡�
            return false;
        }

        distanceResult = Get(iterationT);
        if (distanceResult.GetDistance() <= distance.GetZeroThreshold())
        {
            // ����Ϊ��Чֵ�㡣
            distanceResult.SetDistance(MathType::GetValue(0));
            distanceResult.SetContactTime(iterationT);

            return true;
        }

        auto derivativeResult = GetDerivative(iterationT);
        if (MathType::GetValue(0) <= derivativeResult)
        {
            // ͼ�ε�͹�Ա�֤������������ʱ��������Ϊ�����л�����С���֡�
            return false;
        }

        beginT = iterationT;
        beginDistanceResult = distanceResult;
        beginDerivativeDistanceResult = derivativeResult;

        if (loop + 1 == maximumIterations)
        {
            // δ�ܵ����������������������˴�ʱ������ֵ���Ǹ�ֵ����˱������һ�ξ��롣
            distanceResult.SetDistance(beginDistanceResult.GetDistance());
            distanceResult.SetContactTime(beginT);

            MATHEMATICS_ASSERTION_2(false, "δ�ܵ����������������");

            return true;
        }
    }

    return false;
}

template <typename Real, typename Vector>
void Mathematics::IntervalDistanceBase<Real, Vector>::BisectionMethod()
{
    // ������Ϊ����ʹ�ö��ַ��ҵ����������ĸ���
    auto resultT = MathType::GetValue(0);
    for (auto loop = 0; loop < distance.GetMaximumIterations(); ++loop)
    {
        resultT = MathType::GetRational(1, 2) * (beginT + endT);
        auto derivativeResult = GetDerivative(resultT);
        auto product = derivativeResult * beginDerivativeDistanceResult;
        if (product < -distance.GetZeroThreshold())
        {
            endT = resultT;
            endDerivativeDistanceResult = derivativeResult;
        }
        else if (distance.GetZeroThreshold() < product)
        {
            beginT = resultT;
            beginDerivativeDistanceResult = derivativeResult;
        }
        else
        {
            break;
        }
    }

    distanceResult = Get(resultT);
    distanceResult.SetContactTime(resultT);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>::IsValid() const noexcept
{
    if (MathType::GetValue(0) <= tMin && tMin <= tMax)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H
