// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 17:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_DETAIL_H

#include "DistanceBase.h"
#include "DistanceResultDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Detail/IntervalDistanceDetail.h"
#include "Detail/IntervalDistanceSquaredDetail.h"

template <typename Real, typename Vector>
const Real Mathematics::DistanceBase<Real, Vector>
	::sm_DefaultZeroThreshold{ Math::GetZeroTolerance() };

template <typename Real, typename Vector>
const Real Mathematics::DistanceBase<Real, Vector>
	::sm_DefaultDifferenceStep{ static_cast<Real>(1e-03) };

template <typename Real, typename Vector>
Mathematics::DistanceBase<Real, Vector>
	::DistanceBase()
	:m_MaximumIterations{ sm_DefaultMaximumIterations }, m_ZeroThreshold{ sm_DefaultZeroThreshold }, m_DifferenceStep{ sm_DefaultDifferenceStep }, m_InverseTwoDifferenceStep{ static_cast<Real>(0.5) / m_DifferenceStep }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceBase<Real, Vector>
	::~DistanceBase()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceBase<Real, Vector>
	::IsValid() const noexcept
{
	if (0 < m_MaximumIterations && Math::GetValue(0) <= m_ZeroThreshold && Math::GetValue(0) < m_DifferenceStep &&
		Math::Approximate(static_cast<Real>(0.5) / m_DifferenceStep, m_InverseTwoDifferenceStep, m_ZeroThreshold))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>
	::SetDifferenceStep(Real differenceStep)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(Math::GetValue(0) < differenceStep, "无效的相差步进值\n");

	m_DifferenceStep = differenceStep;
	m_InverseTwoDifferenceStep = static_cast<Real>(0.5) / m_DifferenceStep;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>
	::GetDifferenceStep() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DifferenceStep;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>
	::SetMaximumIterations(int maximumIterations)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(0 < maximumIterations, "无效的最大迭代次数\n");

	m_MaximumIterations = maximumIterations;
}

template <typename Real, typename Vector>
void Mathematics::DistanceBase<Real, Vector>
	::SetZeroThreshold(Real zeroThreshold)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= zeroThreshold, "无效的临界值\n");

	m_ZeroThreshold = zeroThreshold;
}

template <typename Real, typename Vector>
int Mathematics::DistanceBase<Real, Vector>
	::GetMaximumIterations() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaximumIterations;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>
	::GetZeroThreshold() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ZeroThreshold;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>
	::Get() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto result = GetSquared();
	result.SetSqrtDistance();

	return result;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>
	::Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto result = GetSquared(t, lhsVelocity, rhsVelocity);
	result.SetSqrtDistance();

	return result;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>
	::GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 使用有限差分近似： f'(t) = (f(t + h) - f(t - h))/(2 * h)
	auto funcPlus = Get(t + m_DifferenceStep, lhsVelocity, rhsVelocity);
	auto funcMinus = Get(t - m_DifferenceStep, lhsVelocity, rhsVelocity);
	auto derivativeApproximation = m_InverseTwoDifferenceStep * (funcPlus.GetDistance() - funcMinus.GetDistance());

	return derivativeApproximation;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceBase<Real, Vector>
	::GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 如果计算平方距离的导数为特定类别更快的方法，派生类应该重写它。
	auto distance = Get(t, lhsVelocity, rhsVelocity);
	auto derivative = GetDerivative(t, lhsVelocity, rhsVelocity);

	return static_cast<Real>(2) * distance.GetDistance() * derivative;
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>
	::GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 这里的假设是，距离f(t)是一个凸函数。
	// f'(tmin) >= 0，则最小出现在tmin。若f'(tmax) <= 0，则最小出现在tmax。
	// 否则，f'(0) < 0且f'(tmax) > 0 则最小发生在(tmin,tmax)的一些t。

	IntervalDistance<Real, Vector> intervalDistance{ *this,tMin,tMax,lhsVelocity,rhsVelocity };

	return intervalDistance.GetResult();
}

template <typename Real, typename Vector>
const typename Mathematics::DistanceBase<Real, Vector>::DistanceResult Mathematics::DistanceBase<Real, Vector>
	::GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 这里的假设是，距离f(t)是一个凸函数。
	// f'(tmin) >= 0，则最小出现在tmin。若f'(tmax) <= 0，则最小出现在tmax。
	// 否则，f'(0) < 0且f'(tmax) > 0 则最小发生在(tmin,tmax)的一些t。

	IntervalDistanceSquared<Real, Vector> intervalDistanceSquared{ *this,tMin,tMax,lhsVelocity,rhsVelocity };

	return intervalDistanceSquared.GetResult();
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_DETAIL_H
