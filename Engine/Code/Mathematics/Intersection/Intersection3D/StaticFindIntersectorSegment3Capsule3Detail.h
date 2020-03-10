// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H

#include "StaticFindIntersectorSegment3Capsule3.h"
#include "StaticFindIntersectorLine3Capsule3.h" 
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::StaticFindIntersectorSegment3Capsule3(const Segment3& rkSegment, const Capsule3& rkCapsule)
	: mSegment{ rkSegment }, mCapsule{ rkCapsule }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::GetCapsule() const
{
    return mCapsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::Find()
{
	auto quantity = StaticFindIntersectorLine3Capsule3<Real>::Find(mSegment.GetCenterPoint(),mSegment.GetDirection(), mCapsule, mParameter);

    mQuantity = 0;
    for (auto i = 0; i < quantity; ++i)
    {
        if (Math::FAbs(mParameter[i]) <= mSegment.GetExtent())
        {
            mPoint[mQuantity++] = mSegment.GetCenterPoint() + mParameter[i]*mSegment.GetDirection();
        }
    }

    if (mQuantity == 2)
    {
		this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (mQuantity == 1)
    {
		this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
		this->SetIntersectionType(IntersectionType::Empty);
    } 
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Capsule3<Real>
	::GetParameter(int i) const
{
    return mParameter[i];
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H