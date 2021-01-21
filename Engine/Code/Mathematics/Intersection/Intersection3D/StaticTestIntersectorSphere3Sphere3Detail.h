// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSphere3Sphere3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::StaticTestIntersectorSphere3Sphere3(const Sphere3& rkSphere0, const Sphere3& rkSphere1, const Real epsilon)
    : m_Sphere0{ rkSphere0 }, m_Sphere1{ rkSphere1 }
{
	Test();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
    return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
    return m_Sphere1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Sphere3<Real>
	::Test()
{
	auto diff = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
	auto rSum = m_Sphere0.GetRadius() + m_Sphere1.GetRadius();
	if (Vector3DTools::VectorMagnitudeSquared(diff) <= rSum*rSum)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H