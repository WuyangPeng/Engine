// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 10:17)

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
	if (ParentType::IsValid())
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

	// �ڰ�Χ�е�����ϵ�й�����
	auto difference = m_Point - m_Box.GetCenter();

	// ����ƽ������Ͱ�Χ���ϵ�����㡣
	Vector3D closest{ Vector3DTools::DotProduct(difference, m_Box.GetAxis0()),
					  Vector3DTools::DotProduct(difference,m_Box.GetAxis1()),
					  Vector3DTools::DotProduct(difference,m_Box.GetThirdAxis()) };
	auto squaredDistance = Math::GetValue(0);
	auto delta = Math::GetValue(0);

	if (closest.GetX() < -m_Box.GetExtent0())
	{
		delta = closest.GetX() + m_Box.GetExtent0();
		squaredDistance += delta * delta;
		closest.SetX(-m_Box.GetExtent0());
	}
	else if (m_Box.GetExtent0() < closest.GetX())
	{
		delta = closest.GetX() - m_Box.GetExtent0();
		squaredDistance += delta * delta;
		closest.SetX(m_Box.GetExtent0());
	}

	if (closest.GetY() < -m_Box.GetExtent1())
	{
		delta = closest.GetY() + m_Box.GetExtent1();
		squaredDistance += delta * delta;
		closest.SetY(-m_Box.GetExtent1());
	}
	else if (m_Box.GetExtent1() < closest.GetY())
	{
		delta = closest.GetY() - m_Box.GetExtent1();
		squaredDistance += delta * delta;
		closest.SetY(m_Box.GetExtent1());
	}

	if (closest.GetZ() < -m_Box.GetThirdExtent())
	{
		delta = closest.GetZ() + m_Box.GetThirdExtent();
		squaredDistance += delta * delta;
		closest.SetZ(-m_Box.GetThirdExtent());
	}
	else if (m_Box.GetThirdExtent() < closest.GetZ())
	{
		delta = closest.GetZ() - m_Box.GetThirdExtent();
		squaredDistance += delta * delta;
		closest.SetZ(m_Box.GetThirdExtent());
	}

	return DistanceResult{ squaredDistance, Math::GetValue(0), m_Point,
						   m_Box.GetCenter() + closest.GetX() * m_Box.GetAxis0() +
						   closest.GetY() * m_Box.GetAxis1() +
						   closest.GetZ() * m_Box.GetThirdAxis() };
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
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

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H
