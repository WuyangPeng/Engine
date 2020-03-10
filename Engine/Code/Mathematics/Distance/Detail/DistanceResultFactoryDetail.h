// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 17:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H

#include "DistanceResultFactory.h"
#include "DistanceMultipleClosestPointsResultDetail.h"
#include "DistanceClosestPointsParameterResultDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceResultFactory<Real, Vector>
	::DistanceResultFactory()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceResultFactory<Real, Vector>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultImplPtr Mathematics::DistanceResultFactory<Real, Vector>
	::Create(Real distance)
{
	return std::make_shared<DistanceResultImpl<Real,Vector>>(distance);
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultImplPtr Mathematics::DistanceResultFactory<Real, Vector>
	::Create(Real distance, Real contactTime)
{
	return std::make_shared<DistanceContactTimeResult<Real, Vector>>(distance, contactTime); 
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultImplPtr Mathematics::DistanceResultFactory<Real, Vector>
	::Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint)
{
	return std::make_shared<DistanceClosestPointsResult<Real, Vector>>(distance, contactTime, lhsClosestPoint, rhsClosestPoint); 
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultImplPtr Mathematics::DistanceResultFactory<Real, Vector>
	::Create(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
{
	return std::make_shared<DistanceMultipleClosestPointsResult<Real, Vector>>(distance, contactTime, lhsClosestPoints, rhsClosestPoints); 
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultImplPtr Mathematics::DistanceResultFactory<Real, Vector>
	::Create(Real distance, Real contactTime, const Vector& lhsClosestPoint,const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter)
{
	return std::make_shared<DistanceClosestPointsParameterResult<Real, Vector>>(distance, contactTime, lhsClosestPoint, rhsClosestPoint, lhsParameter, rhsParameter); 
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H
 