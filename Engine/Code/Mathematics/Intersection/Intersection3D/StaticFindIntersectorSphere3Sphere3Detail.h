// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorSphere3Sphere3.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::StaticFindIntersectorSphere3Sphere3 (const Sphere3& rkSphere0,const Sphere3& rkSphere1)
	: m_Sphere0{ rkSphere0 }, m_Sphere1{ rkSphere1 }, m_Circle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Math<Real>::GetValue(0) }
{
	Find();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
    return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
    return m_Sphere1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::Find()
{
    // Plane of intersection must have N as its normal.
	auto C1mC0 = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
	auto sqrLen = Vector3DTools::VectorMagnitudeSquared(C1mC0);
	auto r0 = m_Sphere0.GetRadius(), r1 = m_Sphere1.GetRadius();

	auto rSum = r0 + r1;
	auto rSumSqr = rSum*rSum;
    if (sqrLen > rSumSqr)
    {
        // Spheres are disjoint/separated.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }
    if (sqrLen == rSumSqr)
    {
        // Spheres are just touching.  The caller must call
        // GetIntersectionType() to determine what type of intersection has
        // occurred.  In this case, GetContactPoint() should be called, not
        // GetCircle().  The circle parameters are set just in case the caller
        // does not test for intersection type.
        C1mC0.Normalize();
        m_ContactPoint = m_Sphere0.GetCenter() + r0*C1mC0;
		m_Circle = Circle3{ m_ContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::GetZero() };
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

	auto rDif = r0 - r1;
	auto rDifSqr = rDif*rDif;
    if (sqrLen < rDifSqr)
    {
        // One sphere is strictly contained in the other.  The caller must
        // call GetIntersectionType() to determine what type of intersection
        // has occurred.  In this case, neither GetCircle() nor
        // GetContactPoint() should be called.  The circle and contact
        // parameters are set just in case the caller does not test for
        // intersection type, but the choices are arbitrary.
        C1mC0.Normalize();
		m_ContactPoint = (Real{0.5})*(m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
		m_Circle = Circle3{ m_ContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::GetZero() };

     
		this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> (rDif <= Math<Real>::GetZero() ? IT_SPHERE0 : IT_SPHERE1));
        return;
    }
    if (sqrLen == rDifSqr)
    {
        // One sphere is contained in the other sphere but with a single point
        // of contact.  The caller must call GetIntersectionType() to
        // determine what type of intersection has occurred.  In this case,
        // GetContactPoint() should be called.  The circle parameters are set
        // just in case the caller does not test for intersection type.
        C1mC0.Normalize();
      
        if (rDif <= Math<Real>::GetZero())
        {
            m_ContactPoint = m_Sphere1.GetCenter() + r1*C1mC0;
			this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> ( IT_SPHERE0_POINT));
        }
        else
        {
			m_ContactPoint = m_Sphere0.GetCenter() + r0*C1mC0;
			this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> (IT_SPHERE1_POINT));
        }
         
		m_Circle = Circle3(m_ContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::GetZero());

        return;
    }

    // Compute t for which the circle of intersection has center
    // K = C0 + t*(C1 - C0).
    auto t = (Real{0.5})*(Math::GetValue(1) + rDif*rSum/sqrLen);

    // Center and radius of circle of intersection.
 

    // Compute N, U, and V for plane of circle.
    C1mC0.Normalize();
    
	auto vector3DOrthonormalBasis =	Vector3DTools::GenerateComplementBasis(C1mC0);
	m_Circle = Circle3{ m_Sphere0.GetCenter() + t * C1mC0, vector3DOrthonormalBasis.GetUVector(),
					   vector3DOrthonormalBasis.GetVVector(), C1mC0,
				       Math::Sqrt(Math::FAbs(r0*r0 - t * t*sqrLen)) }; 

    // The intersection is a circle.
	this->SetIntersectionType(static_cast<IntersectionType> (IT_CIRCLE));
    return;
}
 
template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetCircle() const
{
    return m_Circle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetContactPoint() const
{
    return m_ContactPoint;
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H