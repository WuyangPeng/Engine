// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H

#include "StaticFindIntersectorRay3Capsule3.h"
#include "StaticFindIntersectorLine3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::StaticFindIntersectorRay3Capsule3(const Ray3& rkRay,const Capsule3& rkCapsule)
	: mRay{ rkRay }, mCapsule{ rkCapsule }
{
	Find();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::GetCapsule() const
{
    return mCapsule;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::Find()
{
    Real t[2];
	auto quantity = StaticFindIntersectorLine3Capsule3<Real>::Find(mRay.GetOrigin(), mRay.GetDirection(), mCapsule, t);

    mQuantity = 0;
    for (auto i = 0; i < quantity; ++i)
    {
        if (t[i] >= Real{})
        {
			mPoint[mQuantity++] = mRay.GetOrigin() + t[i] * mRay.GetDirection();
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
int Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Capsule3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H