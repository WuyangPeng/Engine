// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorSegment3Capsule3.h"
#include "StaticTestIntersectorLine3Capsule3.h" 
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Capsule3<Real>
	::StaticTestIntersectorSegment3Capsule3 (const Segment3& rkSegment, const Capsule3& rkCapsule)
	: m_Segment{ rkSegment }, mCapsule{ rkCapsule }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>
	::GetCapsule() const
{
    return mCapsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Capsule3<Real>
	::Test()
{
	auto distance = DistanceSegment3Segment3<Real>(m_Segment,mCapsule.GetSegment()).Get().GetDistance();
	if (distance <= mCapsule.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}


#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H