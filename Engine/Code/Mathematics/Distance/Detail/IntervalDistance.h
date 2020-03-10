// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:23)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H

#include "IntervalDistanceBase.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class IntervalDistance: public IntervalDistanceBase<Real, Vector>
	{
	public:			
		using ClassType = IntervalDistance<Real, Vector>;
		using ParentType = IntervalDistanceBase<Real, Vector>;
		using DistanceBase = DistanceBase<Real, Vector>;
		using DistanceResult = DistanceResult<Real, Vector>;

	public:
		IntervalDistance(const DistanceBase& distance,Real tMin, Real tMax,const Vector& lhsVelocity,const Vector& rhsVelocity);
		virtual ~IntervalDistance();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	private:	
		virtual const DistanceResult Get(Real t) const override;
		virtual Real GetDerivative(Real t) const override;
	};	 
}

#endif // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_H
