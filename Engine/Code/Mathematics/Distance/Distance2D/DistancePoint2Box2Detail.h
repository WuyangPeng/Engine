// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 19:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H

#include "DistancePoint2Box2.h"
#include "Mathematics/Objects2D/Box2Detail.h" 
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Box2<Real>
	::DistancePoint2Box2(const Vector2D& point, const Box2& box)
	:ParentType{}, m_Point{ point }, m_Box{ box }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint2Box2<Real>
	::~DistancePoint2Box2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Box2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::Vector2D Mathematics::DistancePoint2Box2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::Box2 Mathematics::DistancePoint2Box2<Real>
	::GetBox() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Box;
}

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 在包围盒的坐标系中工作。
	auto difference = m_Point - m_Box.GetCenter();

	// 计算平方距离和包围盒上的最近点。
	Vector2D closest{ Vector2DTools::DotProduct(difference,m_Box.GetFirstAxis()),
					  Vector2DTools::DotProduct(difference,m_Box.GetSecondAxis()) };
	auto squaredDistance = Math<Real>::GetValue(0);
	auto delta = Math<Real>::GetValue(0);

	if (closest.GetXCoordinate() < -m_Box.GetFirstExtent())
	{
		delta = closest.GetXCoordinate() + m_Box.GetFirstExtent();
		squaredDistance += delta * delta;
		closest.SetXCoordinate(-m_Box.GetFirstExtent());
	}
	else if (m_Box.GetFirstExtent() < closest.GetXCoordinate())
	{
		delta = closest.GetXCoordinate() - m_Box.GetFirstExtent();
		squaredDistance += delta * delta;
		closest.SetXCoordinate(m_Box.GetFirstExtent());
	}

	if (closest.GetYCoordinate() < -m_Box.GetSecondExtent())
	{
		delta = closest.GetYCoordinate() + m_Box.GetSecondExtent();
		squaredDistance += delta * delta;
		closest.SetYCoordinate(-m_Box.GetSecondExtent());
	}
	else if (m_Box.GetSecondExtent() < closest.GetYCoordinate())
	{
		delta = closest.GetYCoordinate() - m_Box.GetSecondExtent();
		squaredDistance += delta * delta;
		closest.SetYCoordinate(m_Box.GetSecondExtent());
	}

	return DistanceResult{ squaredDistance, Math<Real>::GetValue(0), m_Point,
						   m_Box.GetCenter() + closest.GetXCoordinate() * m_Box.GetFirstAxis() +
						   closest.GetYCoordinate() * m_Box.GetSecondAxis() };
}

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedBox = m_Box.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedBox };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H
