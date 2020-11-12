// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_H
#define MATHEMATICS_DISTANCE_DISTANCE_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResult.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceBase
	{
	public:
		using ClassType = DistanceBase<Real, Vector>;
		using DistanceResult = DistanceResult<Real, Vector>;
		using Math = Math<Real>;

	public:
		DistanceBase();
		virtual ~DistanceBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// ���ڵ����ƽ���
		void SetDifferenceStep(Real differenceStep);
		Real GetDifferenceStep() const;

		void SetMaximumIterations(int maximumIterations);
		int GetMaximumIterations() const;

		void SetZeroThreshold(Real zeroThreshold);
		Real GetZeroThreshold() const;

		// ��̬�����ѯ��
		// ���루Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
		virtual const DistanceResult Get() const;
		// ����ƽ��
		virtual const DistanceResult GetSquared() const = 0;

		// �������㶯̬�����ѯ��
		// ��Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
		virtual const DistanceResult Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
		virtual const DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const = 0;

		// ΢�ּ��㶯̬�����ѯ��Ĭ��ʹ�����޲�ֹ���f'(t) = (f(t + h) - f(t - h)) / (2 * h)������h = m_DifferenceStep��
		// ��������Ը�����Щ�����ṩ��Ҫ��h�ľ�ȷ��ʽ��ʵ�֡�
		virtual Real GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
		virtual Real GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

		// ��̬�����ѯ������������ʱ����[tmin,tmax]��������֮�����С���롣
		// Ĭ��ʵ�ּ����ǣ�����f(t)��һ��͹������
		virtual const DistanceResult GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
		virtual const DistanceResult GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

	private:
		static constexpr auto sm_DefaultMaximumIterations = 8;
		static const Real sm_DefaultZeroThreshold;
		static const Real sm_DefaultDifferenceStep;

	private:
		// ����ţ�ٷ����������߲�ֵ��
		// Ĭ�� = 8
		int m_MaximumIterations;
		// Ĭ�� = Math<Real>::GetZeroTolerance()
		Real m_ZeroThreshold;

		// Ĭ�� = 1e-03
		Real m_DifferenceStep;
		Real m_InverseTwoDifferenceStep;
	};

	using Distance2f = DistanceBase<float, FloatVector2D>;
	using Distance3f = DistanceBase<float, FloatVector3D>;
	using Distance2d = DistanceBase<double, DoubleVector2D>;
	using Distance3d = DistanceBase<double, DoubleVector3D>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_H
