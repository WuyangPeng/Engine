// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 10:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_DETAIL_H

#include "DistancePoint3Line3.h"
#include "Mathematics/Objects3D/Line3Detail.h" 
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistancePoint3Line3<Real>
	::DistancePoint3Line3(const Vector3D& point, const Line3& line)
	:ParentType{}, m_Point{ point }, m_Line{ line }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint3Line3<Real>
	::~DistancePoint3Line3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Line3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint3Line3<Real>::Vector3D Mathematics::DistancePoint3Line3<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint3Line3<Real>::Line3 Mathematics::DistancePoint3Line3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistancePoint3Line3<Real>::DistanceResult Mathematics::DistancePoint3Line3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_Point - m_Line.GetOrigin();
	auto param = Vector3DTools::DotProduct(m_Line.GetDirection(), difference);
	auto rhsClosestPoint = m_Line.GetOrigin() + param * m_Line.GetDirection();
	difference = rhsClosestPoint - m_Point;

	return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(difference), Real{},m_Point,rhsClosestPoint,Real{},param };
}

template <typename Real>
const typename Mathematics::DistancePoint3Line3<Real>::DistanceResult Mathematics::DistancePoint3Line3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
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

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_DETAIL_H
  