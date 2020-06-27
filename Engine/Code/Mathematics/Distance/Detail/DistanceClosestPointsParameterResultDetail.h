// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 18:59)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H

#include "DistanceClosestPointsParameterResult.h"
#include "DistanceClosestPointsResultDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::DistanceClosestPointsParameterResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter)
	:ParentType{ distance, contactTime,lhsClosestPoint,rhsClosestPoint }, m_LhsParameter{ lhsParameter }, m_RhsParameter{ rhsParameter }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::~DistanceClosestPointsParameterResult()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::GetLhsParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsParameter;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::GetRhsParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsParameter;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::ImplTypePtr Mathematics::DistanceClosestPointsParameterResult<Real, Vector>
	::Clone() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
