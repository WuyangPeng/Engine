// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 19:22)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_DETAIL_H

#include "DistancePoint2Segment2.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h" 
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::DistancePoint2Segment2<Real>
	::DistancePoint2Segment2(const Vector2D& point, const Segment2& segment)
	:ParentType{}, m_Point{ point }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint2Segment2<Real>
	::~DistancePoint2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Segment2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint2Segment2<Real>::Vector2D Mathematics::DistancePoint2Segment2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint2Segment2<Real>::Segment2 Mathematics::DistancePoint2Segment2<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistancePoint2Segment2<Real>::DistanceResult Mathematics::DistancePoint2Segment2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_Point - m_Segment.GetCenterPoint();
	auto param = Vector2DTools::DotProduct(m_Segment.GetDirection(), difference);

	Vector2D rhsClosestPoint;
	if (-m_Segment.GetExtent() < param)
	{
		if (param < m_Segment.GetExtent())
		{
			rhsClosestPoint = m_Segment.GetCenterPoint() + param * m_Segment.GetDirection();
		}
		else
		{
			rhsClosestPoint = m_Segment.GetEndPoint();
		}
	}
	else
	{
		rhsClosestPoint = m_Segment.GetBeginPoint();
	}

	difference = rhsClosestPoint - m_Point;

	return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(difference), Math<Real>::GetValue(0),m_Point,rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistancePoint2Segment2<Real>::DistanceResult Mathematics::DistancePoint2Segment2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedSegment };
	distance.SetZeroThreshold(ParentType::GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_DETAIL_H

