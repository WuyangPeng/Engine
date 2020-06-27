// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H

#include "StaticTestIntersectorSegment3Plane3.h"
#include "StaticTestIntersectorLine3Plane3.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Plane3<Real>
	::StaticTestIntersectorSegment3Plane3(const Segment3& rkSegment, const Plane3& rkPlane)
	:mSegment{ rkSegment }, mPlane{ rkPlane }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Plane3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorSegment3Plane3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Plane3<Real>
	::Test()
{
	auto P0 = mSegment.GetBeginPoint();
	auto sdistance0 = mPlane.DistanceTo(P0);
    if (Math::FAbs(sdistance0) <= Math::sm_ZeroTolerance)
    {
        sdistance0 = Math<Real>::sm_Zero;
    }

	auto P1 = mSegment.GetEndPoint();
	auto sdistance1 = mPlane.DistanceTo(P1);
    if (Math::FAbs(sdistance1) <= Math::sm_ZeroTolerance)
    {
        sdistance1 = Math<Real>::sm_Zero;
    }

	auto prod = sdistance0*sdistance1;
    if (prod < Math<Real>::sm_Zero)
    {
        // The segment passes through the plane.
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (prod > Math<Real>::sm_Zero)
    {
        // The segment is on one side of the plane.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (sdistance0 != Math<Real>::sm_Zero || sdistance1 != Math<Real>::sm_Zero)
    {
        // A segment end point touches the plane.
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // The segment is coincident with the plane.
	this->SetIntersectionType(IntersectionType::Segment);
   
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H