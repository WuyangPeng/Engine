// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:12)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorCapsule3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>
	::StaticTestIntersectorCapsule3Capsule3 (const Capsule3& capsule0, const Capsule3& capsule1)
	: mCapsule0{ capsule0 }, mCapsule1{ capsule1 }
{
	Test();
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>
	::GetCapsule0 () const
{
    return mCapsule0;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>
	::GetCapsule1 () const
{
    return mCapsule1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>
	::Test ()
{
    auto distance = DistanceSegment3Segment3<Real>(mCapsule0.GetSegment(),mCapsule1.GetSegment()).Get().GetDistance();
	auto rSum = mCapsule0.GetRadius() + mCapsule1.GetRadius();
    if(distance <= rSum)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{

		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_DETAIL_H