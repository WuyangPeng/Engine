// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorTriangle3Sphere3.h"
#include "StaticTestIntersectorSegment3Sphere3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Triangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>
	::StaticTestIntersectorTriangle3Sphere3 (const Triangle3& triangle, const Sphere3& sphere)
	: m_Triangle{ triangle }, m_Sphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>
	::GetTriangle () const
{
    return m_Triangle;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>
	::GetSphere () const
{
    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>
	::Test ()
{
	DistancePoint3Triangle3<Real> calc{ m_Sphere.GetCenter(), m_Triangle };
	auto sqrDistance = calc.GetSquared().GetDistance();
	auto rSqr = m_Sphere.GetRadius()*m_Sphere.GetRadius();
    if( sqrDistance <= rSqr)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H