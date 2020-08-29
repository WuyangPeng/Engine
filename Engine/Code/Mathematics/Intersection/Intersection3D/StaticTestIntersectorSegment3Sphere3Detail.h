// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:40)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorSegment3Capsule3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Sphere3<Real>
	::StaticTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere)
	: mSegment{ segment }, mSphere{ sphere }
{
     ZeroThreshold = Math::GetZeroTolerance();
	 Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Sphere3<Real>	
	::Test()
{
	auto diff = mSegment.GetCenterPoint() - mSphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - mSphere.GetRadius()*mSphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(mSegment.GetDirection(),diff);
	auto discr = a1*a1 - a0;
    if (discr < Math<Real>::GetZero())
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto tmp0 = mSegment.GetExtent()*mSegment.GetExtent() + a0;
	auto tmp1 = (static_cast<Real>(2))*a1*mSegment.GetExtent();
	auto qm = tmp0 - tmp1;
	auto qp = tmp0 + tmp1;
    if (qm*qp <= Math<Real>::GetZero())
    {
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

	if (qm > Math<Real>::GetZero() && Math::FAbs(a1) < mSegment.GetExtent())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H