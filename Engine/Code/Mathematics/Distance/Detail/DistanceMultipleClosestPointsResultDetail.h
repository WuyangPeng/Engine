// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 19:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceMultipleClosestPointsResult.h"
#include "DistanceClosestPointsResultDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real, typename Vector>
Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
	:ParentType{ distance, contactTime }, m_LhsClosestPoints{ lhsClosestPoints }, m_RhsClosestPoints{ rhsClosestPoints }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::~DistanceMultipleClosestPointsResult()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_LhsClosestPoints.size() == m_RhsClosestPoints.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
const Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::GetLhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetLhsClosestPointSize(), "À˜“˝¥ÌŒÛ£°");

	return m_LhsClosestPoints[index];
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::GetRhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetRhsClosestPointSize(), "À˜“˝¥ÌŒÛ£°");

	return m_RhsClosestPoints[index];
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::GetLhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_LhsClosestPoints.size());
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::GetRhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_RhsClosestPoints.size());
}

template <typename Real, typename Vector>
typename Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::ImplTypePtr Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>
	::Clone() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
