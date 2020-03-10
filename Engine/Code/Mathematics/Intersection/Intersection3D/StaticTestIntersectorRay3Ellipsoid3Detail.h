// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 13:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorRay3Ellipsoid3.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>
	::StaticTestIntersectorRay3Ellipsoid3 (const Ray3& rkRay,const Ellipsoid3& rkEllipsoid)
	: mRay{ rkRay }, mEllipsoid{ rkEllipsoid }
{
	Test();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return mEllipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>
	::Test()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the ray is X = P+t*D.
    // Substitute the ray equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

	auto M = mEllipsoid.GetMatrix();

	auto diff = mRay.GetOrigin() - mEllipsoid.GetCenter();
	auto matDir = M*mRay.GetDirection();
	auto matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(mRay.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(mRay.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - (Real)1;

    // No intersection if Q(t) has no real roots.
	auto discr = a1*a1 - a0*a2;
    if (discr < Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // Test whether ray origin is inside ellipsoid.
    if (a0 <= Real{})
    {
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // At this point, Q(0) = a0 > 0 and Q(t) has real roots.  It is also
    // the case that a2 > 0, since M is positive definite, implying that
    // D^T*M*D > 0 for any nonzero vector D.  Thus, an intersection occurs
    // only when Q'(0) < 0.
	if (a1 < Real{})
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H