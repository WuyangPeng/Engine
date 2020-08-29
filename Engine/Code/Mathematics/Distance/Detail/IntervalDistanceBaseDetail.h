// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 19:02)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H

#include "IntervalDistanceBase.h"
#include "Mathematics/Distance/DistanceResultDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real, typename Vector>
Mathematics::IntervalDistanceBase<Real, Vector>
	::IntervalDistanceBase(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity)
	:m_Distance{ distance }, m_TMin{ tMin }, m_TMax{ tMax }, m_LhsVelocity{ lhsVelocity },
	 m_RhsVelocity{ rhsVelocity }, m_DistanceResult{ Math::GetValue(0) }, m_BeginT{ tMin }, m_EndT{ tMax },
	 m_BeginDistanceResult{ Math::GetValue(0) }, m_BeginDerivativeDistanceResult{ Math::GetValue(0) }, 
	 m_EndDistanceResult{ Math::GetValue(0) }, m_EndDerivativeDistanceResult{ Math::GetValue(0) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, typename Vector>
void Mathematics::IntervalDistanceBase<Real, Vector>
	::Solve()
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

// private
template <typename Real, typename Vector>
const typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>
	::GetDistanceResult(Real t) const
{
	return m_Distance.Get(t, m_LhsVelocity, m_RhsVelocity);
}

// protected
template <typename Real, typename Vector>
const typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>
	::GetDistanceResultSquared(Real t) const
{
	return m_Distance.GetSquared(t, m_LhsVelocity, m_RhsVelocity);
}

// private
template <typename Real, typename Vector>
Real Mathematics::IntervalDistanceBase<Real, Vector>
	::GetDerivativeDistanceResult(Real t) const
{
	return m_Distance.GetDerivative(t, m_LhsVelocity, m_RhsVelocity);
}

// protected
template <typename Real, typename Vector>
Real Mathematics::IntervalDistanceBase<Real, Vector>
	::GetDerivativeDistanceResultSquared(Real t) const
{
	return m_Distance.GetDerivativeSquared(t, m_LhsVelocity, m_RhsVelocity);
}

// private
template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>
	::CheckBeginMonotonicFunction()
{
	m_BeginDistanceResult = Get(m_BeginT);
	if (m_BeginDistanceResult.GetDistance() <= m_Distance.GetZeroThreshold())
	{
		// 距离为有效值零。对象是在最初位置接触。
		m_BeginDistanceResult.Set(Math::GetValue(0), m_BeginT);
		m_DistanceResult = m_BeginDistanceResult;

		return true;
	}

	m_BeginDerivativeDistanceResult = GetDerivative(m_BeginT);
	if (Math::GetValue(0) <= m_BeginDerivativeDistanceResult)
	{
		// 距离在[0,tmax]增加。 
		m_BeginDistanceResult.SetContactTime(m_BeginT);
		m_DistanceResult = m_BeginDistanceResult;

		return true;
	}

	return false;
}

// private
template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>
	::CheckEndMonotonicFunction()
{
	m_EndDistanceResult = Get(m_EndT);
	if (m_EndDistanceResult.GetDistance() <= m_Distance.GetZeroThreshold())
	{
		// 距离为有效值零。
		m_EndDistanceResult.Set(Math::GetValue(0), m_EndT);
		m_DistanceResult = m_EndDistanceResult;

		return true;
	}

	m_EndDerivativeDistanceResult = GetDerivative(m_EndT);
	if (m_EndDerivativeDistanceResult <= Math::GetValue(0))
	{
		// 距离在[0,tmax]增加。 
		m_EndDistanceResult.SetContactTime(m_EndT);
		m_DistanceResult = m_EndDistanceResult;

		return true;
	}

	return false;
}

// private
template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>
	::Iteration()
{
	// 开始用牛顿法处理计算当距离为零的时间。
	// 在此过程中，如果我们确定该距离不能为零，我们将切换到一个最小数值。
	auto maximumIterations = m_Distance.GetMaximumIterations();
	for (auto loop = 0; loop < maximumIterations; ++loop)
	{
		// 计算下一个牛顿迭代
		auto iterationT = m_BeginT - m_BeginDistanceResult.GetDistance() / m_BeginDerivativeDistanceResult;
		if (m_TMax <= iterationT)
		{
			// 图形的凸性保证当该条件发生时，距离总为正。切换到最小数字。
			return false;
		}

		m_DistanceResult = Get(iterationT);
		if (m_DistanceResult.GetDistance() <= m_Distance.GetZeroThreshold())
		{
			// 距离为有效值零。
			m_DistanceResult.SetDistance(Math::GetValue(0));
			m_DistanceResult.SetContactTime(iterationT);

			return true;
		}

		auto derivativeResult = GetDerivative(iterationT);
		if (Math::GetValue(0) <= derivativeResult)
		{
			// 图形的凸性保证当该条件发生时，距离总为正。切换到最小数字。
			return false;
		}

		m_BeginT = iterationT;
		m_BeginDistanceResult = m_DistanceResult;
		m_BeginDerivativeDistanceResult = derivativeResult;

		if (loop + 1 == maximumIterations)
		{
			// 未能迭代所需次数内收敛。到达此处时，导数值总是负值，因此报告最后一次距离。
			m_DistanceResult.SetDistance(m_BeginDistanceResult.GetDistance());
			m_DistanceResult.SetContactTime(m_BeginT);

			MATHEMATICS_ASSERTION_2(false, "未能迭代所需次数内收敛");

			return true;
		}
	}

	return false;
}

// private
template <typename Real, typename Vector>
void Mathematics::IntervalDistanceBase<Real, Vector>
	::BisectionMethod()
{
	// 距离总为正。使用二分法找到导数函数的根。
	auto resultT = Math::GetValue(0);
	for (auto loop = 0; loop < m_Distance.GetMaximumIterations(); ++loop)
	{
		resultT = static_cast<Real>(0.5) * (m_BeginT + m_EndT);
		auto derivativeResult = GetDerivative(resultT);
		auto product = derivativeResult * m_BeginDerivativeDistanceResult;
		if (product < -m_Distance.GetZeroThreshold())
		{
			m_EndT = resultT;
			m_EndDerivativeDistanceResult = derivativeResult;
		}
		else if (m_Distance.GetZeroThreshold() < product)
		{
			m_BeginT = resultT;
			m_BeginDerivativeDistanceResult = derivativeResult;
		}
		else
		{
			break;
		}
	}

	m_DistanceResult = Get(resultT);
	m_DistanceResult.SetContactTime(resultT);
}

template <typename Real, typename Vector>
Mathematics::IntervalDistanceBase<Real, Vector>
	::~IntervalDistanceBase()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::IntervalDistanceBase<Real, Vector>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_TMin && m_TMin <= m_TMax)
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
const typename Mathematics::IntervalDistanceBase<Real, Vector>::DistanceResult Mathematics::IntervalDistanceBase<Real, Vector>
	::GetResult() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DistanceResult;
}

#endif // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASED_ETAIL_H
