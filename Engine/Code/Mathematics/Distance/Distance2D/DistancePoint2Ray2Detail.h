// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 19:22)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_DETAIL_H 

#include "DistancePoint2Ray2.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h" 

template <typename Real>
Mathematics::DistancePoint2Ray2<Real>
	::DistancePoint2Ray2(const Vector2D& point, const Ray2& ray)
	:ParentType{}, m_Point{ point }, m_Ray{ ray }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint2Ray2<Real>
	::~DistancePoint2Ray2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Ray2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::Vector2D Mathematics::DistancePoint2Ray2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::Ray2 Mathematics::DistancePoint2Ray2<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_Point - m_Ray.GetOrigin();
	auto param = Vector2DTools::DotProduct(m_Ray.GetDirection(), difference);

	if (param <= Math<Real>::sm_Zero)
	{
		param = Math<Real>::sm_Zero;
	}

	auto rhsClosestPoint = m_Ray.GetOrigin() + param * m_Ray.GetDirection();
	difference = rhsClosestPoint - m_Point;

	return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(difference), Math<Real>::sm_Zero,m_Point,rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedRay = m_Ray.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedRay };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_DETAIL_H
