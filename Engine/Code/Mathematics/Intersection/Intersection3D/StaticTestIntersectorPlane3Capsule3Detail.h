// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorPlane3Capsule3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::StaticTestIntersectorPlane3Capsule3(const Plane3& plane,const Capsule3& capsule)
	: mPlane{ plane }, mCapsule{ capsule }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::GetCapsule() const
{
    return mCapsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::Test()
{
	auto pDist = mPlane.DistanceTo(mCapsule.GetSegment().GetEndPoint());
	auto nDist = mPlane.DistanceTo(mCapsule.GetSegment().GetBeginPoint());
    if (pDist*nDist <= Real{})
    {
        // Capsule segment endpoints on opposite sides of the plane.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // Endpoints on same side of plane, but the endpoint spheres (with
    // radius of the capsule) might intersect the plane.
	if (Math::FAbs(pDist) <= mCapsule.GetRadius()|| Math::FAbs(nDist) <= mCapsule.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::CapsuleIsCulled() const
{
	auto pDist = mPlane.DistanceTo(mCapsule.GetSegment().GetEndPoint());
    if (pDist < Real{})
    {
		auto nDist = mPlane.DistanceTo(mCapsule.GetSegment().GetBeginPoint());
        if (nDist < Real{})
        {
            if (pDist <= nDist)
            {
				return (pDist <= -mCapsule.GetRadius());				
            }
            else
            {
				return (nDist <= -mCapsule.GetRadius());
            }
        }
    }

    return false;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H