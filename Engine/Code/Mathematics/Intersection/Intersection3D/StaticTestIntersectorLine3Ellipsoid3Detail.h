// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:20)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorLine3Ellipsoid3.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::StaticTestIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid, const Real epsilon)
    : m_Line{ line }, m_Ellipsoid{ ellipsoid }, mNegativeThreshold{}, mPositiveThreshold{}
{
	Test();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::GetLine() const
{
    return m_Line;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return m_Ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::Test()
{
    // The ellipsoid is (X-K)^T*M*(X-K)-1 = 0 and the line is X = P+t*D.
    // Substitute the line equation into the ellipsoid equation to obtain
    // a quadratic equation
    //   Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    // where a2 = D^T*M*D, a1 = D^T*M*(P-K), and a0 = (P-K)^T*M*(P-K)-1.

	auto M = m_Ellipsoid.GetMatrix();

	auto diff = m_Line.GetOrigin() - m_Ellipsoid.GetCenter();
	auto matDir = M*m_Line.GetDirection();
	auto matDiff = M*diff;
	auto a2 = Vector3DTools::DotProduct(m_Line.GetDirection(),matDir);
	auto a1 = Vector3DTools::DotProduct(m_Line.GetDirection(),matDiff);
	auto a0 = Vector3DTools::DotProduct(diff,matDiff) - Math::GetValue(1);

    // Intersection occurs if Q(t) has real roots.
	auto discr = a1*a1 - a0*a2;
	if (discr >= mNegativeThreshold)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::SetNegativeThreshold(Real negThreshold)
{
    if (negThreshold <= Math<Real>::GetValue(0))
    {
        mNegativeThreshold = negThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "Negative threshold must be nonpositive.");
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::GetNegativeThreshold() const
{
    return mNegativeThreshold;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::SetPositiveThreshold(Real posThreshold)
{
    if (posThreshold >= Math<Real>::GetValue(0))
    {
        mPositiveThreshold = posThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "Positive threshold must be nonnegative.");
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>
	::GetPositiveThreshold() const
{
    return mPositiveThreshold;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H