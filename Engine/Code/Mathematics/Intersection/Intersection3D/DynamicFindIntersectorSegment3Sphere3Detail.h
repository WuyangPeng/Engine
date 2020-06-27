// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 16:31)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::DynamicFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSegment{ segment }, mSphere{ sphere }
{
	mQuantity = 0;
	ZeroThreshold = Math::sm_ZeroTolerance;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
	return mSphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::Find()
{
	// Check if initially intersecting.
	StaticFindIntersectorSegment3Sphere3<Real> inter{ mSegment,mSphere };
	if (inter.IsIntersection())
	{
		SetContactTime(Math<Real>::sm_Zero);
		this->SetIntersectionType(IntersectionType::Other);
		// 相交点赋值
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
	relVelocity.Normalize();// unit-length vector
	Segment3 path{ (static_cast<Real>(0.5)) * this->GetTMax()*relSpeed,mSphere.GetCenter() + (static_cast<Real>(0.5)) * this->GetTMax() * relSpeed * relVelocity,relVelocity };

	StaticFindIntersectorSegment3Capsule3<Real> intr{ path, capsule };
	if (!intr.IsIntersection())
	{
		SetContactTime(Math<Real>::sm_Zero);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// We now know the sphere will intersect the segment.  This can happen
	// either at a segment end point or at a segment interior point.  We
	// need to determine which.
	SetContactTime((intr.GetParameter(0) + path.GetExtent()) / relSpeed);
	mQuantity = 1;
	this->SetIntersectionType(IntersectionType::Point);

	auto MCenter = mSphere.GetCenter() + this->GetContactTime()*this->GetRhsVelocity();
	auto MOrigin = mSegment.GetCenterPoint() + this->GetContactTime()*this->GetLhsVelocity();
	auto origin = Vector3DTools::DotProduct(mSegment.GetDirection(), MOrigin);
	auto negEnd = origin - mSegment.GetExtent();
	auto posEnd = origin + mSegment.GetExtent();
	auto center = Vector3DTools::DotProduct(mSegment.GetDirection(), MCenter);

	if (center < negEnd)
	{
		// Intersection at segment end point P-e*D.
		mPoint[0] = MOrigin - mSegment.GetExtent()*mSegment.GetDirection();
	}
	else if (center > posEnd)
	{
		// Intersection at segment end point P+e*D.
		mPoint[0] = MOrigin + mSegment.GetExtent()*mSegment.GetDirection();
	}
	else
	{
		// Intersection with interior point on edge.  Use the projection
		// along direction axis to find which point that is.
		mPoint[0] = MOrigin + (center - origin)*mSegment.GetDirection();
	}

	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSegmentParameter(int i) const
{
	return mSegmentParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H