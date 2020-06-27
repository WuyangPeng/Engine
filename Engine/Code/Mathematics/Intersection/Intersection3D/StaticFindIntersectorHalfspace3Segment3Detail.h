// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "StaticFindIntersectorHalfspace3Segment3.h"
#include "IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment)
	: mHalfspace{ halfspace }, mSegment{ segment }
{
	mQuantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::Find()
{
	// Start with the segment and clip it against the plane.
	mQuantity = 2;
	mPoint[0] = mSegment.GetBeginPoint();;
	mPoint[1] = mSegment.GetEndPoint();

	ClipConvexPolygonAgainstPlane<Real>(-mHalfspace.GetNormal(), -mHalfspace.GetConstant(), mQuantity, mPoint);

	if (mQuantity > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const  Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H