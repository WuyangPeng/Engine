// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorSegment3Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"
 
template <typename Real>
Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::StaticFindIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid)
	: mSegment{ segment }, mEllipsoid{ ellipsoid }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return mEllipsoid;
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::Find()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the line is X = P+t*D.
    // Substitute the line equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

	auto M = mEllipsoid.GetMatrix();

	auto diff = mSegment.GetCenterPoint() - mEllipsoid.GetCenter();
	auto  matDir = M*mSegment.GetDirection();
	auto  matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(mSegment.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(mSegment.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - static_cast<Real>(1);

    // Intersection occurs if Q(t) has real roots with t >= 0.
	auto discr = a1*a1 - a0*a2;
    Real t[2];
    if (discr < Math<Real>::GetZero())
    {
		this->SetIntersectionType(IntersectionType::Empty);
        mQuantity = 0;
    }
    else if (discr > Math::GetZeroTolerance())
    {
        Real root = Math::Sqrt(discr);
        Real inv = (static_cast<Real>(1))/a2;
        t[0] = (-a1 - root)*inv;
        t[1] = (-a1 + root)*inv;

        // assert: t0 < t1 since a2 > 0
		StaticFindIntersector1<Real> intr{ t[0], t[1], -mSegment.GetExtent(),  mSegment.GetExtent() };
       

        mQuantity = intr.GetNumIntersections();
        if (mQuantity == 2)
        {
			this->SetIntersectionType(IntersectionType::Segment);
            mPoint[0] = mSegment.GetCenterPoint() + intr.GetIntersection(0) * mSegment.GetDirection();
            mPoint[1] = mSegment.GetCenterPoint() + intr.GetIntersection(1) * mSegment.GetDirection();
        }
        else if (mQuantity == 1)
        {
			this->SetIntersectionType(IntersectionType::Point);
            mPoint[0] = mSegment.GetCenterPoint() + intr.GetIntersection(0) * mSegment.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
        }
    }
    else
    {
        t[0] = -a1/a2;
        if (Math::FAbs(t[0]) <= mSegment.GetExtent())
        {
			this->SetIntersectionType(IntersectionType::Point);
            mQuantity = 1;
            mPoint[0] = mSegment.GetCenterPoint() + t[0]*mSegment.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
            mQuantity = 0;
        }
    }    
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H