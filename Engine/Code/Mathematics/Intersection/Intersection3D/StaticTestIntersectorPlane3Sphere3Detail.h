// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorPlane3Sphere3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Sphere3<Real>
	::StaticTestIntersectorPlane3Sphere3(const Plane3& plane,const Sphere3& sphere)
	: mPlane{ plane }, mSphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Sphere3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorPlane3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Sphere3<Real>
	::Test()
{
	auto signedDistance = mPlane.DistanceTo(mSphere.GetCenter());
	if (Math::FAbs(signedDistance) <= mSphere.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Sphere3<Real>
	::SphereIsCulled() const
{
	auto signedDistance = mPlane.DistanceTo(mSphere.GetCenter());
    return signedDistance <= -mSphere.GetRadius();
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H