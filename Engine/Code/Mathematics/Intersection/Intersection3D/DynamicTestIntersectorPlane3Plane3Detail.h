// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "DynamicTestIntersectorPlane3Plane3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1,
										 Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Plane0{ plane0 }, m_Plane1{ plane1 }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::GetPlane0() const
{
	return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::GetPlane1() const
{
	return m_Plane1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::Test()
{
	auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
	if (Math::FAbs(dot) < Math::GetValue(1) - Math::GetZeroTolerance())
	{
		// The planes are initially intersecting.  Linear velocities will
		// not change the fact that they are intersecting.
		SetContactTime(Math::GetValue(0));
		this->SetIntersectionType(IntersectionType::Line);
		return;
	}

	// Check if planes are already coplanar.
	auto cDiff = Math::GetValue(0);
	if (dot >= Math::GetValue(0))
	{
		// Normals are in same direction, need to look at c0-c1.
		cDiff = m_Plane0.GetConstant() - m_Plane1.GetConstant();
	}
	else
	{
		// Normals are in opposite directions, need to look at c0+c1.
		cDiff = m_Plane0.GetConstant() + m_Plane1.GetConstant();
	}

	if (Math::FAbs(cDiff) < Math::GetZeroTolerance())
	{
		// Planes are initially the same.
		SetContactTime(Math::GetValue(0));
		this->SetIntersectionType(IntersectionType::Plane);
		return;
	}

	// The planes are parallel and separated.  Determine when they will
	// become coplanar.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), relVelocity);
	if (Math::FAbs(dot) < Math::GetZeroTolerance())
	{
		// The relative motion of the planes keeps them parallel.
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	SetContactTime(cDiff / dot);
	if (Math::GetValue(0) <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
	{
		// The planes are moving towards each other and will meet within the
		// specified time interval.
		this->SetIntersectionType(IntersectionType::Plane);
		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
	return;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H