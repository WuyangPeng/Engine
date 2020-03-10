// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:32)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H
 
#include "StaticFindIntersectorCircle3Plane3.h"
#include "StaticFindIntersectorPlane3Plane3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::StaticFindIntersectorCircle3Plane3(const Circle3& circle,const Plane3& plane)
	:mCircle{ circle }, mPlane{ plane }
{
	Find();
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::GetCircle() const
{
    return mCircle;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::GetPlane() const
{
    return mPlane;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::Find()
{
    mQuantity = 0;

    // Construct the plane of the circle.
	Plane3 CPlane{ mCircle.GetNormal(),mCircle.GetCenter() };

    // Compute the intersection of this plane with the input plane.
	StaticFindIntersectorPlane3Plane3<Real> intr{ mPlane, CPlane };
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
	auto diff = line.GetOrigin() - mCircle.GetCenter();
	auto a2 = Vector3DTools::VectorMagnitudeSquared(line.GetDirection());
	auto a1 = Vector3DTools::DotProduct(diff,line.GetDirection());
	auto a0 = Vector3DTools::VectorMagnitudeSquared(diff) - mCircle.GetRadius()*mCircle.GetRadius();

	auto discr = a1*a1 - a0*a2;
    if (discr < Real{})
    {
        // No real roots, the circle does not intersect the plane.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	this->SetIntersectionType(IntersectionType::Point);

	auto inv = ((Real)1)/a2;
    if (discr < Math::sm_ZeroTolerance)
    {
        // One repeated root, the circle just touches the plane.
        mQuantity = 1;
		mPoint[0] = line.GetOrigin() - (a1*inv)*line.GetDirection();
        return;
    }

    // Two distinct, real-valued roots, the circle intersects the plane in
    // two points.
	auto root = Math::Sqrt(discr);
    mQuantity = 2;
    mPoint[0] = line.GetOrigin() - ((a1 + root)*inv)*line.GetDirection();
	mPoint[1] = line.GetOrigin() - ((a1 - root)*inv)*line.GetDirection();
   
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>
	::GetIntersectionCircle() const
{
    return mCircle;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_DETAIL_H