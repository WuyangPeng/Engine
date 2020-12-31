// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 16:31)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3.h"
#include "StaticFindIntersectorSegment3Sphere3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::DynamicFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Segment{ segment }, m_Sphere{ sphere }
{
	m_Quantity = 0;
	ZeroThreshold = Math::GetZeroTolerance();
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
	return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::Find()
{
	// Check if initially intersecting.
	StaticFindIntersectorSegment3Sphere3<Real> inter{ m_Segment,m_Sphere };
	if (inter.IsIntersection())
	{
		SetContactTime(Math<Real>::GetZero());
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

	Capsule3<Real> capsule{ m_Segment,m_Sphere.GetRadius() };

	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto relSpeed = Vector3DTools::VectorMagnitude(relVelocity);
	relVelocity.Normalize();// unit-length vector
	Segment3 path{ ( Math::GetRational(1,2)) * this->GetTMax()*relSpeed,m_Sphere.GetCenter() + ( Math::GetRational(1,2)) * this->GetTMax() * relSpeed * relVelocity,relVelocity };

	StaticFindIntersectorSegment3Capsule3<Real> intr{ path, capsule };
	if (!intr.IsIntersection())
	{
		SetContactTime(Math<Real>::GetZero());
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// We now know the sphere will intersect the segment.  This can happen
	// either at a segment end point or at a segment interior point.  We
	// need to determine which.
	SetContactTime((intr.GetParameter(0) + path.GetExtent()) / relSpeed);
	m_Quantity = 1;
	this->SetIntersectionType(IntersectionType::Point);

	auto MCenter = m_Sphere.GetCenter() + this->GetContactTime()*this->GetRhsVelocity();
	auto MOrigin = m_Segment.GetCenterPoint() + this->GetContactTime()*this->GetLhsVelocity();
	auto origin = Vector3DTools::DotProduct(m_Segment.GetDirection(), MOrigin);
	auto negEnd = origin - m_Segment.GetExtent();
	auto posEnd = origin + m_Segment.GetExtent();
	auto center = Vector3DTools::DotProduct(m_Segment.GetDirection(), MCenter);

	if (center < negEnd)
	{
		// Intersection at segment end point P-e*D.
		m_Point[0] = MOrigin - m_Segment.GetExtent()*m_Segment.GetDirection();
	}
	else if (center > posEnd)
	{
		// Intersection at segment end point P+e*D.
		m_Point[0] = MOrigin + m_Segment.GetExtent()*m_Segment.GetDirection();
	}
	else
	{
		// Intersection with interior point on edge.  Use the projection
		// along direction axis to find which point that is.
		m_Point[0] = MOrigin + (center - origin)*m_Segment.GetDirection();
	}

	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>
	::GetSegmentParameter(int i) const
{
	return m_SegmentParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H