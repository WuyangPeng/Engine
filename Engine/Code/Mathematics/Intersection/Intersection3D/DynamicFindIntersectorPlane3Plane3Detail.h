// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:30)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "DynamicFindIntersectorPlane3Plane3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::DynamicFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mPlane0{ plane0 }, mPlane1{ plane1 }, mIntrLine{ Vector3D::sm_Zero, Vector3D::sm_Zero }
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::GetPlane0() const
{
	return mPlane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::GetPlane1() const
{
	return mPlane1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::Find()
{
	auto dot = Vector3DTools::DotProduct(mPlane0.GetNormal(), mPlane1.GetNormal());
	if (Math::FAbs(dot) < static_cast<Real>(1) - Math::sm_ZeroTolerance)
	{
		// The planes are initially intersecting.  Linear velocities will
		// not change the fact that they are intersecting.
		SetContactTime(Math::sm_Zero);

		auto invDet = (static_cast<Real>(1)) / (static_cast<Real>(1) - dot * dot);
		auto c0 = (mPlane0.GetConstant() - dot * mPlane1.GetConstant())*invDet;
		auto c1 = (mPlane1.GetConstant() - dot * mPlane0.GetConstant())*invDet;
		this->SetIntersectionType(IntersectionType::Line);
		mIntrLine = Line3{ c0*mPlane0.GetNormal() + c1 * mPlane1.GetNormal(),Vector3DTools::UnitCrossProduct(mPlane0.GetNormal(),mPlane1.GetNormal()) };

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

		mIntrPlane = mPlane0;
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
		mIntrPlane = Plane3{ mPlane0.GetNormal(),mPlane0.GetConstant() + this->GetContactTime()*(Vector3DTools::DotProduct(mPlane0.GetNormal(), this->GetLhsVelocity())) };

		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
	return;
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::GetIntersectionLine() const
{
	return mIntrLine;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>
	::GetIntersectionPlane() const
{
	return mIntrPlane;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H