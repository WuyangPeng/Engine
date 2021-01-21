// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorRay3Capsule3.h"
#include "StaticFindIntersectorLine3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Segment3Detail.h" 

template <typename Real>
Mathematics::StaticTestIntersectorRay3Capsule3<Real>::StaticTestIntersectorRay3Capsule3(const Ray3& rkRay, const Capsule3& rkCapsule, const Real epsilon)
    : m_Ray{ rkRay }, m_Capsule{ rkCapsule }
{
	Test();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Capsule3<Real>
	::GetRay() const
{
    return m_Ray;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorRay3Capsule3<Real>
	::GetCapsule() const
{
    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Capsule3<Real>
	::Test()
{
	auto distance = DistanceRay3Segment3<Real>(m_Ray, m_Capsule.GetSegment()).Get().GetDistance();
	if (distance <= m_Capsule.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
   
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H