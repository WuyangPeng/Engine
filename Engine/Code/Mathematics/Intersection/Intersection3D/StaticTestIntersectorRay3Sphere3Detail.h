// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:37)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorRay3Sphere3.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Sphere3<Real>
	::StaticTestIntersectorRay3Sphere3(const Ray3& ray,const Sphere3& sphere)
	: mRay{ ray }, mSphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Sphere3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorRay3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Sphere3<Real>
	::Test()
{
    auto diff = mRay.GetOrigin() - mSphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - mSphere.GetRadius()*mSphere.GetRadius();
    if (a0 <= Math<Real>::GetValue(0))
    {
        // P is inside the sphere
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }
    // else: P is outside the sphere

	auto a1 = Vector3DTools::DotProduct(mRay.GetDirection(),diff);
    if (a1 >= Math<Real>::GetValue(0))
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // Quadratic has a real root if discriminant is nonnegative.
	if (a1*a1 >= a0)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H