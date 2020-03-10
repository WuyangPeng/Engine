// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 10:01)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H

#include "DistancePoint3Box3.h"
#include "Mathematics/Objects3D/Box3Detail.h" 
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistancePoint3Box3<Real>
	::DistancePoint3Box3(const Vector3D& point, const Box3& box)
	:ParentType{}, m_Point{ point }, m_Box{ box }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint3Box3<Real>
	::~DistancePoint3Box3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Box3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::Vector3D Mathematics::DistancePoint3Box3<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::Box3 Mathematics::DistancePoint3Box3<Real>
	::GetBox() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Box;
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// 在包围盒的坐标系中工作。
	auto difference = m_Point - m_Box.GetCenter();

	// 计算平方距离和包围盒上的最近点。
	Vector3D closest{ Vector3DTools::DotProduct(difference, m_Box.GetFirstAxis()),
					  Vector3DTools::DotProduct(difference,m_Box.GetSecondAxis()),
					  Vector3DTools::DotProduct(difference,m_Box.GetThirdAxis()) };
	Real squaredDistance { };
	Real delta { };

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

	if (closest.GetZCoordinate() < -m_Box.GetThirdExtent())
	{
		delta = closest.GetZCoordinate() + m_Box.GetThirdExtent();
		squaredDistance += delta * delta;
		closest.SetZCoordinate(-m_Box.GetThirdExtent());
	}
	else if (m_Box.GetThirdExtent() < closest.GetZCoordinate())
	{
		delta = closest.GetZCoordinate() - m_Box.GetThirdExtent();
		squaredDistance += delta * delta;
		closest.SetZCoordinate(m_Box.GetThirdExtent());
	}

	return DistanceResult{ squaredDistance, Real{}, m_Point,
						   m_Box.GetCenter() + closest.GetXCoordinate() * m_Box.GetFirstAxis() +
						   closest.GetYCoordinate() * m_Box.GetSecondAxis() +
						   closest.GetZCoordinate() * m_Box.GetThirdAxis() };
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 
	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedBox = m_Box.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedBox };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H
 