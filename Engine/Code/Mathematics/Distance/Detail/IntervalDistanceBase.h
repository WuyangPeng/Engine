// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:08)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H

#include "Mathematics/Distance/DistanceFwd.h"
#include "Mathematics/Distance/DistanceResult.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
	template <typename Real, typename Vector>
	class IntervalDistanceBase : private boost::noncopyable
	{
	public:
		using ClassType = IntervalDistanceBase<Real, Vector>;
		using DistanceBase = DistanceBase<Real, Vector>;
		using DistanceResult = DistanceResult<Real, Vector>;
		using Math = Math<Real>;

	public:
		IntervalDistanceBase(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);
		virtual ~IntervalDistanceBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		const DistanceResult GetResult() const;

	protected:
		void Solve();
		const DistanceResult GetDistanceResultSquared(Real t) const;
		Real GetDerivativeDistanceResultSquared(Real t) const;
		const DistanceResult GetDistanceResult(Real t) const;
		Real GetDerivativeDistanceResult(Real t) const;

	private:
		bool CheckBeginMonotonicFunction();
		bool CheckEndMonotonicFunction();
		bool Iteration();
		void BisectionMethod();
		virtual const DistanceResult Get(Real t) const = 0;
		virtual Real GetDerivative(Real t) const = 0;

	private:
		const DistanceBase& m_Distance;
		Real m_TMin;
		Real m_TMax;
		Vector m_LhsVelocity;
		Vector m_RhsVelocity;
		DistanceResult m_DistanceResult;

		Real m_BeginT;
		Real m_EndT;
		DistanceResult m_BeginDistanceResult;
		Real m_BeginDerivativeDistanceResult;
		DistanceResult m_EndDistanceResult;
		Real m_EndDerivativeDistanceResult;
	};
}

#endif // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
