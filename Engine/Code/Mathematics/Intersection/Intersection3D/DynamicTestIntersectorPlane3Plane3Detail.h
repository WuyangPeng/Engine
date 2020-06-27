// Copyright (c) 2011-2020
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
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mPlane0{ plane0 }, mPlane1{ plane1 }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::GetPlane0() const
{
	return mPlane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::GetPlane1() const
{
	return mPlane1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorPlane3Plane3<Real>
	::Test()
{
	auto dot = Vector3DTools::DotProduct(mPlane0.GetNormal(), mPlane1.GetNormal());
	if (Math::FAbs(dot) < static_cast<Real>(1) - Math::sm_ZeroTolerance)
	{
		// The planes are initially intersecting.  Linear velocities will
		// not change the fact that they are intersecting.
		SetContactTime(Math::sm_Zero);
		this->SetIntersectionType(IntersectionType::Line);
		return;
	}

	// Check if planes are already coplanar.
	auto cDiff = Math::sm_Zero;
	if (dot >= Math::sm_Zero)
	{
		// Normals are in same direction, need to look at c0-c1.
		cDiff = mPlane0.GetConstant() - mPlane1.GetConstant();
	}
	else
	{
		// Normals are in opposite directions, need to look at c0+c1.
		cDiff = mPlane0.GetConstant() + mPlane1.GetConstant();
	}

	if (Math::FAbs(cDiff) < Math::sm_ZeroTolerance)
	{
		// Planes are initially the same.
		SetContactTime(Math::sm_Zero);
		this->SetIntersectionType(IntersectionType::Plane);
		return;
	}

	// The planes are parallel and separated.  Determine when they will
	// become coplanar.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	dot = Vector3DTools::DotProduct(mPlane0.GetNormal(), relVelocity);
	if (Math::FAbs(dot) < Math::sm_ZeroTolerance)
	{
		// The relative motion of the planes keeps them parallel.
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	SetContactTime(cDiff / dot);
	if (Math::sm_Zero <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
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