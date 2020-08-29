// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 19:02)

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
		// ����Ϊ��Чֵ�㡣�����������λ�ýӴ���
		m_BeginDistanceResult.Set(Math::GetValue(0), m_BeginT);
		m_DistanceResult = m_BeginDistanceResult;

		return true;
	}

	m_BeginDerivativeDistanceResult = GetDerivative(m_BeginT);
	if (Math::GetValue(0) <= m_BeginDerivativeDistanceResult)
	{
		// ������[0,tmax]���ӡ� 
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
		// ����Ϊ��Чֵ�㡣
		m_EndDistanceResult.Set(Math::GetValue(0), m_EndT);
		m_DistanceResult = m_EndDistanceResult;

		return true;
	}

	m_EndDerivativeDistanceResult = GetDerivative(m_EndT);
	if (m_EndDerivativeDistanceResult <= Math::GetValue(0))
	{
		// ������[0,tmax]���ӡ� 
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
	// ��ʼ��ţ�ٷ�������㵱����Ϊ���ʱ�䡣
	// �ڴ˹����У��������ȷ���þ��벻��Ϊ�㣬���ǽ��л���һ����С��ֵ��
	auto maximumIterations = m_Distance.GetMaximumIterations();
	for (auto loop = 0; loop < maximumIterations; ++loop)
	{
		// ������һ��ţ�ٵ���
		auto iterationT = m_BeginT - m_BeginDistanceResult.GetDistance() / m_BeginDerivativeDistanceResult;
		if (m_TMax <= iterationT)
		{
			// ͼ�ε�͹�Ա�֤������������ʱ��������Ϊ�����л�����С���֡�
			return false;
		}

		m_DistanceResult = Get(iterationT);
		if (m_DistanceResult.GetDistance() <= m_Distance.GetZeroThreshold())
		{
			// ����Ϊ��Чֵ�㡣
			m_DistanceResult.SetDistance(Math::GetValue(0));
			m_DistanceResult.SetContactTime(iterationT);

			return true;
		}

		auto derivativeResult = GetDerivative(iterationT);
		if (Math::GetValue(0) <= derivativeResult)
		{
			// ͼ�ε�͹�Ա�֤������������ʱ��������Ϊ�����л�����С���֡�
			return false;
		}

		m_BeginT = iterationT;
		m_BeginDistanceResult = m_DistanceResult;
		m_BeginDerivativeDistanceResult = derivativeResult;

		if (loop + 1 == maximumIterations)
		{
			// δ�ܵ����������������������˴�ʱ������ֵ���Ǹ�ֵ����˱������һ�ξ��롣
			m_DistanceResult.SetDistance(m_BeginDistanceResult.GetDistance());
			m_DistanceResult.SetContactTime(m_BeginT);

			MATHEMATICS_ASSERTION_2(false, "δ�ܵ����������������");

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
	// ������Ϊ����ʹ�ö��ַ��ҵ����������ĸ���
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
