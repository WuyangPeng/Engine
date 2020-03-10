// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 17:23)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H

#include "IntervalDistance.h"
#include "IntervalDistanceBaseDetail.h" 

template <typename Real, typename Vector>
Mathematics::IntervalDistance<Real, Vector>
	::IntervalDistance(const DistanceBase& distance, Real tMin, Real tMax,const Vector& lhsVelocity, const Vector& rhsVelocity)
	:ParentType{ distance,tMin,tMax,lhsVelocity,rhsVelocity }
{
	ParentType::Solve();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
 
template <typename Real, typename Vector>
Mathematics::IntervalDistance<Real, Vector>
	::~IntervalDistance()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::IntervalDistance<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())	
		return true;	
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
const typename Mathematics::IntervalDistance<Real, Vector>::DistanceResult Mathematics::IntervalDistance<Real, Vector>
	::Get( Real t ) const
{
	return ParentType:: GetDistanceResult(t);
}

template <typename Real, typename Vector>
Real Mathematics::IntervalDistance<Real, Vector>
	::GetDerivative( Real t ) const
{
	return ParentType::GetDerivativeDistanceResult(t);
}

#endif // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_DETAIL_H
 