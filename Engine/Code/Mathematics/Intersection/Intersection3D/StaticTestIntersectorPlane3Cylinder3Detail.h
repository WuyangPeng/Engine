// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H

#include "StaticTestIntersectorPlane3Cylinder3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::StaticTestIntersectorPlane3Cylinder3(const Plane3& rkPlane, const Cylinder3& rkCylinder, const Real epsilon)
    : m_Plane{ rkPlane }, m_Cylinder{ rkCylinder }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>
	::GetCylinder() const
{
    return m_Cylinder;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>
	::Test()
{
    // Compute extremes of signed distance Dot(N,X)-d for points on the
    // cylinder.  These are
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
	auto sDist = m_Plane.DistanceTo(m_Cylinder.GetAxis().GetOrigin());
	auto absNdW = Math::FAbs(Vector3DTools::DotProduct(m_Plane.GetNormal(),m_Cylinder.GetAxis().GetDirection()));
	auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNdW*absNdW));
	auto term = m_Cylinder.GetRadius()*root + (Real{0.5})*m_Cylinder.GetHeight()*absNdW;

    // Intersection occurs if and only if 0 is in the interval [min,max].
	if (Math::FAbs(sDist) <= term)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>
	::CylinderIsCulled() const
{
    // Compute extremes of signed distance Dot(N,X)-d for points on the
    // cylinder.  These are
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
	auto sDist = m_Plane.DistanceTo(m_Cylinder.GetAxis().GetOrigin());
	auto absNdW = Math::FAbs(Vector3DTools::DotProduct(m_Plane.GetNormal(),m_Cylinder.GetAxis().GetDirection()));
	auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNdW*absNdW));
	auto term = m_Cylinder.GetRadius()*root + (Real{0.5})*m_Cylinder.GetHeight()*absNdW;

    // Culling occurs if and only if max <= 0.
    return sDist + term <= Math<Real>::GetValue(0);
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H