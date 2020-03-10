// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 18:13)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_DETAIL_H

#include "DistancePoint2Line2.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h" 

template <typename Real>
Mathematics::DistancePoint2Line2<Real>
	::DistancePoint2Line2(const Vector2D& point, const Line2& line)
	:ParentType{}, m_Point{ point }, m_Line{ line }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint2Line2<Real>
	::~DistancePoint2Line2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Line2<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint2Line2<Real>::Vector2D Mathematics::DistancePoint2Line2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint2Line2<Real>::Line2 Mathematics::DistancePoint2Line2<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistancePoint2Line2<Real>::DistanceResult Mathematics::DistancePoint2Line2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_Point - m_Line.GetOrigin();
	auto param = Vector2DTools::DotProduct(m_Line.GetDirection(), difference);
	auto rhsClosestPoint = m_Line.GetOrigin() + param * m_Line.GetDirection();
	difference = rhsClosestPoint - m_Point;

	return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(difference), Real{}, m_Point,rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistancePoint2Line2<Real>::DistanceResult Mathematics::DistancePoint2Line2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 
	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedLine = m_Line.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedLine };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_DETAIL_H
 