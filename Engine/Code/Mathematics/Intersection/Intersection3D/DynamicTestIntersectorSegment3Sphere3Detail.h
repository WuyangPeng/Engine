// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:48)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorSegment3Sphere3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>
	::DynamicTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSegment{ segment }, mSphere{ sphere }
{
	ZeroThreshold = Math::GetZeroTolerance();
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
	return mSphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>
	::Test()
{
	// Check if initially intersecting.
	StaticTestIntersectorSegment3Sphere3<Real> inte{ mSegment,mSphere };
	SetIntersectionType(inte.GetIntersectionType());
	if (inte.IsIntersection())
	{
		return;
	}

	// Substract the segment velocity from the sphere velocity so that
	// the calculations are based in the coordinate system of the segment.
	// In this system, the line is of course stationary.  The sphere spans
	// a capsule, but instead we will "grow" the segment by the sphere radius
	// and shrink the sphere to its center.  The problem is now to detect
	// the first time the moving center intersects the capsule formed by
	// the line segment and sphere radius.

	Capsule3<Real> capsule{ mSegment,mSphere.GetRadius() };

	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto relSpeed = Vector3DTools::VectorMagnitude(relVelocity);
	relVelocity.Normalize();
	Segment3 path{ (static_cast<Real>(0.5)) * this->GetTMax() * relSpeed,mSphere.GetCenter() + (static_cast<Real>(0.5))*this->GetTMax() * relSpeed * relVelocity,relVelocity };

	StaticTestIntersectorSegment3Capsule3<Real> intersector{ path, capsule };
	SetIntersectionType(intersector.GetIntersectionType());
}


#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H