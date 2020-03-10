// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 17:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResult.h"
#include "DistanceContactTimeResultDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsResult<Real, Vector>
	::DistanceClosestPointsResult(Real distance, Real contactTime,const Vector& lhsClosestPoint, const Vector& rhsClosestPoint)
	:ParentType{ distance, contactTime }, m_LhsClosestPoint{ lhsClosestPoint }, m_RhsClosestPoint{ rhsClosestPoint }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsResult<Real, Vector>
	::~DistanceClosestPointsResult()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceClosestPointsResult<Real, Vector>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
const Vector Mathematics::DistanceClosestPointsResult<Real, Vector>
	::GetLhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetLhsClosestPointSize(), "À˜“˝¥ÌŒÛ£°");

	SYSTEM_UNUSED_ARG(index);

	return m_LhsClosestPoint;
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceClosestPointsResult<Real, Vector>
	::GetRhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetRhsClosestPointSize(), "À˜“˝¥ÌŒÛ£°");

	SYSTEM_UNUSED_ARG(index);

	return m_RhsClosestPoint;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>
	::GetLhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return sm_PointSize;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>
	::GetRhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return sm_PointSize;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsResult<Real, Vector>::ImplTypePtr Mathematics::DistanceClosestPointsResult<Real, Vector>
	::Clone() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
 