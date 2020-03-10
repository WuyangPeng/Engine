// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "StaticTestIntersectorHalfspace3Segment3.h"
#include "IntersectorUtility3.h"

template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>
	::StaticTestIntersectorHalfspace3Segment3 (const Plane3& halfspace, const Segment3& segment)
	: mHalfspace{ halfspace }, mSegment{ segment }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
    return mHalfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>
	::Test ()
{
    Vector3D segment[2]{mSegment.GetBeginPoint(),mSegment.GetEndPoint() };

    Real fmin, fmax;
    IntersectorAxis<Real>::GetProjection(mHalfspace.GetNormal(), segment, fmin, fmax);
	if (fmin <= mHalfspace.GetConstant())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H