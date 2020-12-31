// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorPlane3Sphere3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::StaticFindIntersectorPlane3Sphere3(const Plane3& plane,const Sphere3& sphere)
	: m_Plane{ plane }, m_Sphere{ sphere }, m_Circle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Math<Real>::GetValue(0) }
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetSphere() const
{
    return m_Sphere;
}

 
template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::Find()
{
	auto signedDistance = m_Plane.DistanceTo(m_Sphere.GetCenter());
	auto distance = Math::FAbs(signedDistance);
	auto center = m_Sphere.GetCenter() - signedDistance*m_Plane.GetNormal();
	auto normal = m_Plane.GetNormal();
    if (distance <= m_Sphere.GetRadius())
    {
        // The sphere intersects the plane in a circle.  The circle is
        // degenerate when distance is equal to m_Sphere.GetRadius(), in which
        // case the circle radius is zero.
		auto radius = Math::Sqrt(Math::FAbs(m_Sphere.GetRadius()*m_Sphere.GetRadius() - distance*distance));
		this->SetIntersectionType(IntersectionType::Point);
		m_Circle = Circle3{ center, Vector3D::sm_Zero, Vector3D::sm_Zero, normal, radius };
        return;
    }

    // Additional indication that the circle is invalid.
	Real radius = (Real)-1;
	m_Circle = Circle3{ center, Vector3D::sm_Zero, Vector3D::sm_Zero, normal, radius };
	this->SetIntersectionType(IntersectionType::Empty);    
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::SphereIsCulled() const
{
	auto signedDistance = m_Plane.DistanceTo(m_Sphere.GetCenter());
    return signedDistance <= -m_Sphere.GetRadius();
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetCircle() const
{
    return m_Circle;
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H