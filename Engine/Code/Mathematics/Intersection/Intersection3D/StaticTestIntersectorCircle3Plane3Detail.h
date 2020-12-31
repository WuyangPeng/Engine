// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:12)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H

#include "StaticTestIntersectorCircle3Plane3.h"
#include "StaticFindIntersectorPlane3Plane3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorCircle3Plane3<Real>
	::StaticTestIntersectorCircle3Plane3 (const Circle3& circle,const Plane3& plane)
	:m_Circle{ circle }, m_Plane{ plane }
{
	Test();
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticTestIntersectorCircle3Plane3<Real>
	::GetCircle () const
{
    return m_Circle;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorCircle3Plane3<Real>
	::GetPlane () const
{
    return m_Plane;
}

template <typename Real>
void Mathematics::StaticTestIntersectorCircle3Plane3<Real>
	::Test ()
{
    // Construct the plane of the circle.
	Plane3 CPlane{ m_Circle.GetNormal(),m_Circle.GetCenter() };

    // Compute the intersection of this plane with the input plane.
	StaticFindIntersectorPlane3Plane3<Real> intr{ m_Plane,CPlane };
    if (!intr.IsIntersection())
    {
        // Planes are parallel and nonintersecting.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intr.GetIntersectionType() == IntersectionType::Plane)
    {
        // Planes are the same, the circle is the common intersection set.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // The planes intersect in a line.
	auto line = intr.GetIntersectionLine();

    // Locate one or two points that are on the circle and line.  If the
    // line is t*D+P, the circle center is C, and the circle radius is r,
    // then r^2 = |t*D+P-C|^2 = |D|^2*t^2 + 2*Dot(D,P-C)*t + |P-C|^2.  This
    // is a quadratic equation of the form:  a2*t^2 + 2*a1*t + a0 = 0.
	auto diff = line.GetOrigin() - m_Circle.GetCenter();
	auto a2 = Vector3DTools::VectorMagnitudeSquared(line.GetDirection());
	auto a1 = Vector3DTools::DotProduct(diff,line.GetDirection());
	auto a0 =  Vector3DTools::VectorMagnitudeSquared(diff) - m_Circle.GetRadius()*m_Circle.GetRadius();

    // Real-valued roots imply an intersection.
	auto discr = a1*a1 - a0*a2;
	this->SetIntersectionType(discr >= Math<Real>::GetZero() ? IntersectionType::Point : IntersectionType::Empty); 
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H