// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorSegment3Ellipsoid3.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>
	::StaticTestIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid)
	: m_Segment{ segment }, mEllipsoid{ ellipsoid }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return mEllipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>
	::Test()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the segment is X = P+t*D.
    // Substitute the segment equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

	auto M = mEllipsoid.GetMatrix();

	auto diff = m_Segment.GetCenterPoint() - mEllipsoid.GetCenter();
	auto matDir = M*m_Segment.GetDirection();
	auto matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(m_Segment.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - Math::GetValue(1);

    // No intersection if Q(t) has no real roots.
	auto discr = a1*a1 - a0*a2;
    if (discr < Math<Real>::GetValue(0))
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // Test whether segment origin is inside ellipsoid.
    if (a0 <= Math<Real>::GetValue(0))
    {
		this->SetIntersectionType(IntersectionType::Other);
		return;
    }

    // At this point, Q(0) = a0 > 0 and Q(t) has real roots.  It is also
    // the case that a2 > 0, since M is positive definite, implying that
    // D^T*M*D > 0 for any nonzero vector D.

    Real q, qder, e = m_Segment.GetExtent();

    if (a1 >= Math<Real>::GetValue(0))
    {
        // Roots are possible only on [-e,0], e is the segment extent.  At
        // least one root occurs if Q(-e) <= 0 or if Q(-e) > 0 and Q'(-e) < 0.
        q = a0 + e*(((Real)-2)*a1 + a2*e);
        if (q <= Math<Real>::GetValue(0))
        {
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }

        qder = a1 - a2*e;
        if (qder < Math<Real>::GetValue(0))
        {
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }
    }
    else
    {
        // Roots are only possible on [0,e], e is the segment extent.  At
        // least one root occurs if Q(e) <= 0 or if Q(e) > 0 and Q'(e) > 0.
        q = a0 + e*((Math::GetValue(2))*a1 + a2*e);
        if (q <= Real{0.0})
        {
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }

        qder = a1 + a2*e;
        if (qder < Math<Real>::GetValue(0))
        {
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }
    }

	this->SetIntersectionType(IntersectionType::Empty);
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H