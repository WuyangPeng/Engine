// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H

#include "StaticTestIntersectorSphere3Frustum3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Frustum3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::StaticTestIntersectorSphere3Frustum3(const Sphere3& sphere, const Frustum3& frustum, const Real epsilon)
    : m_Sphere{ sphere }, m_Frustum{ frustum }
{
	Test();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Frustum3<Real>
	::GetSphere() const
{
    return m_Sphere;
}

template <typename Real>
const Mathematics::Frustum3<Real> Mathematics::StaticTestIntersectorSphere3Frustum3<Real>
	::GetFrustum() const
{
    return m_Frustum;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Frustum3<Real>
	::Test()
{
	auto distance = DistancePoint3Frustum3<Real>(m_Sphere.GetCenter(),m_Frustum).Get().GetDistance();

	if (distance <= m_Sphere.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H