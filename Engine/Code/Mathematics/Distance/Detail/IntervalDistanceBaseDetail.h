///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:14)

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
    // 这里的假设是，距离f(t)是一个凸函数。
    // f'(tmin) >= 0，则最小出现在tmin。若f'(tmax) <= 0，则最小出现在tmax。
    // 否则，f'(0) < 0且f'(tmax) > 0 则最小发生在(tmin,tmax)的一些t。
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
        // 距离为有效值零。对象是在最初位置接触。
        beginDistanceResult.Set(MathType::GetValue(0), beginT);
        distanceResult = beginDistanceResult;

        return true;
    }

    beginDerivativeDistanceResult = GetDerivative(beginT);
    if (MathType::GetValue(0) <= beginDerivativeDistanceResult)
    {
        // 距离在[0,tmax]增加。
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
        // 距离为有效值零。
        endDistanceResult.Set(MathType::GetValue(0), endT);
        distanceResult = endDistanceResult;

        return true;
    }

    endDerivativeDistanceResult = GetDerivative(endT);
    if (endDerivativeDistanceResult <= MathType::GetValue(0))
    {
        // 距离在[0,tmax]增加。
        endDistanceResult.SetContactTime(endT);
        distanceResult = endDistanceResult;

        return true;
    }

    return false;
}

template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>::Iteration()
{
    // 开始用牛顿法处理计算当距离为零的时间。
    // 在此过程中，如果我们确定该距离不能为零，我们将切换到一个最小数值。
    const auto maximumIterations = distance.GetMaximumIterations();
    for (auto loop = 0; loop < maximumIterations; ++loop)
    {
        // 计算下一个牛顿迭代
        auto iterationT = beginT - beginDistanceResult.GetDistance() / beginDerivativeDistanceResult;
        if (tMax <= iterationT)
        {
            // 图形的凸性保证当该条件发生时，距离总为正。切换到最小数字。
            return false;
        }

        distanceResult = Get(iterationT);
        if (distanceResult.GetDistance() <= distance.GetZeroThreshold())
        {
            // 距离为有效值零。
            distanceResult.SetDistance(MathType::GetValue(0));
            distanceResult.SetContactTime(iterationT);

            return true;
        }

        auto derivativeResult = GetDerivative(iterationT);
        if (MathType::GetValue(0) <= derivativeResult)
        {
            // 图形的凸性保证当该条件发生时，距离总为正。切换到最小数字。
            return false;
        }

        beginT = iterationT;
        beginDistanceResult = distanceResult;
        beginDerivativeDistanceResult = derivativeResult;

        if (loop + 1 == maximumIterations)
        {
            // 未能迭代所需次数内收敛。到达此处时，导数值总是负值，因此报告最后一次距离。
            distanceResult.SetDistance(beginDistanceResult.GetDistance());
            distanceResult.SetContactTime(beginT);

            MATHEMATICS_ASSERTION_2(false, "未能迭代所需次数内收敛");

            return true;
        }
    }

    return false;
}

template <typename Real, typename Vector>
void Mathematics::IntervalDistanceBase<Real, Vector>::BisectionMethod()
{
    // 距离总为正。使用二分法找到导数函数的根。
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
