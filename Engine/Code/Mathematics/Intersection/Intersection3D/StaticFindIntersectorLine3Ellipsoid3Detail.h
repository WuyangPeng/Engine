// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorLine3Ellipsoid3.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::StaticFindIntersectorLine3Ellipsoid3(const Line3& line,const Ellipsoid3& ellipsoid)
	:mLine{ line }, mEllipsoid{ ellipsoid },mNegativeThreshold{},mPositiveThreshold{}
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return mEllipsoid;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::Find()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the line is X = P+t*D.
    // Substitute the line equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

    auto M = mEllipsoid.GetMatrix();

	auto diff = mLine.GetOrigin() - mEllipsoid.GetCenter();
	auto matDir = M*mLine.GetDirection();
	auto matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(mLine.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(mLine.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - (Real)1;

    // Intersection occurs if Q(t) has real roots.
	auto discr = a1*a1 - a0*a2;
    Real t[2];
    if (discr < mNegativeThreshold)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        mQuantity = 0;
    }
    else if (discr > mPositiveThreshold)
    {
		this->SetIntersectionType(IntersectionType::Segment);
        mQuantity = 2;

		auto root = Math::Sqrt(discr);
		auto inv = ((Real)1)/a2;
        t[0] = (-a1 - root)*inv;
        t[1] = (-a1 + root)*inv;
        mPoint[0] = mLine.GetOrigin() + t[0]*mLine.GetDirection();
        mPoint[1] = mLine.GetOrigin() + t[1]*mLine.GetDirection();
    }
    else
    {
		this->SetIntersectionType(IntersectionType::Point);
        mQuantity = 1;

        t[0] = -a1/a2;
        mPoint[0] = mLine.GetOrigin() + t[0]*mLine.GetDirection();
    }   
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::SetNegativeThreshold(Real negThreshold)
{
    if (negThreshold <= Real{})
    {
        mNegativeThreshold = negThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "Negative threshold must be nonpositive.");
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetNegativeThreshold() const
{
    return mNegativeThreshold;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::SetPositiveThreshold(Real posThreshold)
{
    if (posThreshold >= Real{})
    {
        mPositiveThreshold = posThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "Positive threshold must be nonnegative.");
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>
	::GetPositiveThreshold() const
{
    return mPositiveThreshold;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H