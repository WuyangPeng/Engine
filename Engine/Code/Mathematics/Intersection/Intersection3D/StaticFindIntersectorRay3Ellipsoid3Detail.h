// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorRay3Ellipsoid3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::StaticFindIntersectorRay3Ellipsoid3 (const Ray3& rkRay,const Ellipsoid3& rkEllipsoid)
    : mRay(rkRay),mEllipsoid(rkEllipsoid)
{
	Find();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return mEllipsoid;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::Find()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the line is X = P+t*D.
    // Substitute the line equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

	auto M = mEllipsoid.GetMatrix();

	auto  diff = mRay.GetOrigin() - mEllipsoid.GetCenter();
	auto  matDir = M*mRay.GetDirection();
	auto  matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(mRay.GetDirection(), matDir);
	auto a1 = Vector3DTools::DotProduct(mRay.GetDirection(), matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - Math::GetValue(1);

    // Intersection occurs if Q(t) has real roots with t >= 0.
	auto discr = a1*a1 - a0*a2;
    Real t[2];
    if (discr < Math<Real>::GetZero())
    {
		this->SetIntersectionType(IntersectionType::Empty);
        mQuantity = 0;
    }
    else if (discr > Math<Real>::GetZero())
    {
		auto root = Math::Sqrt(discr);
		auto inv = (Math::GetValue(1))/a2;
        t[0] = (-a1 - root)*inv;
        t[1] = (-a1 + root)*inv;

        if (t[0] >= Math<Real>::GetZero())
        {
			this->SetIntersectionType(IntersectionType::Segment);
            mQuantity = 2;
			mPoint[0] = mRay.GetOrigin() + t[0] * mRay.GetDirection();
			mPoint[1] = mRay.GetOrigin() + t[1] * mRay.GetDirection();
        }
        else if (t[1] >= Math<Real>::GetZero())
        {
			this->SetIntersectionType(IntersectionType::Point);
            mQuantity = 1;
			mPoint[0] = mRay.GetOrigin() + t[1] * mRay.GetDirection();
            t[0] = t[1];
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
            mQuantity = 0;
        }
    }
    else
    {
        t[0] = -a1/a2;
        if (t[0] >= Math<Real>::GetZero())
        {
			this->SetIntersectionType(IntersectionType::Point);
            mQuantity = 1;
			mPoint[0] = mRay.GetOrigin() + t[0] * mRay.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
            mQuantity = 0;
        }
    }   
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H