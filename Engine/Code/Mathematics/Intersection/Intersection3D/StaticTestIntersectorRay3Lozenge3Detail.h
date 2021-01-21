// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorRay3Lozenge3.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Rectangle3Detail.h"

 
template <typename Real>
Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::StaticTestIntersectorRay3Lozenge3(const Ray3& ray, const Lozenge3& lozenge, const Real epsilon)
    : m_Ray{ ray }, mLozenge{ lozenge }
{
	Test();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Lozenge3<Real>
	::GetRay() const
{
    return m_Ray;
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorRay3Lozenge3<Real>
	::GetLozenge() const
{
    return mLozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Lozenge3<Real>
	::Test()
{
	auto distance = DistanceRay3Rectangle3<Real>(m_Ray, mLozenge.GetRectangle()).Get().GetDistance();

	if (distance <= mLozenge.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H