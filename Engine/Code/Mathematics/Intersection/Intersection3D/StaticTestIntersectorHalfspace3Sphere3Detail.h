// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorHalfspace3Sphere3.h"
#include "IntersectorUtility3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::StaticTestIntersectorHalfspace3Sphere3(const Plane3& rkHalfspace, const Sphere3& rkSphere, const Real epsilon)
    : m_Halfspace{ rkHalfspace }, m_Sphere{ rkSphere }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::GetHalfspace() const noexcept
{
    return m_Halfspace;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::GetSphere() const noexcept
{
    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>
	::Test()
{
	auto distance = Vector3DTools::DotProduct(m_Halfspace.GetNormal(),m_Sphere.GetCenter());
	if (distance <= m_Halfspace.GetConstant() + m_Sphere.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H