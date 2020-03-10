// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:50)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H

#include "IntervalDistance.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class IntervalDistanceSquared : public IntervalDistanceBase<Real,Vector>
	{
	public:		
		using ClassType = IntervalDistanceSquared<Real, Vector>;
		using ParentType = IntervalDistanceBase<Real, Vector>;
		using DistanceBase = DistanceBase<Real, Vector>;
		using DistanceResult = DistanceResult<Real, Vector>;

	public:
		IntervalDistanceSquared(const DistanceBase& distance,Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);
		virtual ~IntervalDistanceSquared();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	private:	
		virtual const DistanceResult Get(Real t) const override;
		virtual Real GetDerivative(Real t) const override;
	};	 
}

#endif // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_SQUARED_H
