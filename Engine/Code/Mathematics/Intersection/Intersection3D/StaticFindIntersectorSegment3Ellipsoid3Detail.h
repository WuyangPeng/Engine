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
	: m_Segment{ segment }, mEllipsoid{ ellipsoid }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetSegment() const
{
    return m_Segment;
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

	auto diff = m_Segment.GetCenterPoint() - mEllipsoid.GetCenter();
	auto  matDir = M*m_Segment.GetDirection();
	auto  matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(m_Segment.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - Math::GetValue(1);

    // Intersection occurs if Q(t) has real roots with t >= 0.
	auto discr = a1*a1 - a0*a2;
    Real t[2];
    if (discr < Math<Real>::GetZero())
    {
		this->SetIntersectionType(IntersectionType::Empty);
        m_Quantity = 0;
    }
    else if (discr > Math::GetZeroTolerance())
    {
        Real root = Math::Sqrt(discr);
        Real inv = (Math::GetValue(1))/a2;
        t[0] = (-a1 - root)*inv;
        t[1] = (-a1 + root)*inv;

        // assert: t0 < t1 since a2 > 0
		StaticFindIntersector1<Real> intr{ t[0], t[1], -m_Segment.GetExtent(),  m_Segment.GetExtent() };
       

        m_Quantity = intr.GetNumIntersections();
        if (m_Quantity == 2)
        {
			this->SetIntersectionType(IntersectionType::Segment);
            m_Point[0] = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
            m_Point[1] = m_Segment.GetCenterPoint() + intr.GetIntersection(1) * m_Segment.GetDirection();
        }
        else if (m_Quantity == 1)
        {
			this->SetIntersectionType(IntersectionType::Point);
            m_Point[0] = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
        }
    }
    else
    {
        t[0] = -a1/a2;
        if (Math::FAbs(t[0]) <= m_Segment.GetExtent())
        {
			this->SetIntersectionType(IntersectionType::Point);
            m_Quantity = 1;
            m_Point[0] = m_Segment.GetCenterPoint() + t[0]*m_Segment.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
            m_Quantity = 0;
        }
    }    
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H