// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_DETAIL_H

#include "StaticFindIntersectorSphere3Cone3.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Cone3<Real>
	::StaticFindIntersectorSphere3Cone3(const Sphere3& rkSphere,const Cone3& rkCone)
	: mSphere{ rkSphere }, mCone{ rkCone }
{
	Find();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>
	::GetSphere() const
{
    return mSphere;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>
	::GetCone() const
{
    return mCone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Cone3<Real>
	::Find()
{
    // Test whether cone vertex is in sphere.
	auto diff = mSphere.GetCenter() - mCone.GetVertex();
	auto rSqr = mSphere.GetRadius()*mSphere.GetRadius();
	auto lenSqr = Vector3DTools::VectorMagnitudeSquared(diff);
    if (lenSqr <= rSqr)
    {
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // Test whether sphere center is in cone.
	auto dot = Vector3DTools::DotProduct(diff,mCone.GetAxis());
	auto dotSqr = dot*dot;
	auto cosSqr = mCone.GetCosAngle()*mCone.GetCosAngle();
    if (dotSqr >= lenSqr*cosSqr && dot > Math<Real>::sm_Zero)
    {
        // Sphere center is inside cone, so sphere and cone intersect.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // Sphere center is outside cone.  Problem now reduces to looking for
    // an intersection between circle and ray in the plane containing
    // cone vertex and spanned by cone axis and vector from vertex to
    // sphere center.

    // Ray is t*D+V (t >= 0) where |D| = 1 and dot(A,D) = cos(angle).
    // Also, D = e*A+f*(C-V).  Plugging ray equation into sphere equation
    // yields Real^2 = |t*D+V-C|^2, so the quadratic for intersections is
    // t^2 - 2*dot(D,C-V)*t + |C-V|^2 - Real^2 = 0.  An intersection occurs
    // if and only if the discriminant is nonnegative.  This test becomes
    //
    //     dot(D,C-V)^2 >= dot(C-V,C-V) - Real^2
    //
    // Note that if the right-hand side is nonpositive, then the inequality
    // is true (the sphere contains V).  I have already ruled this out in
    // the first block of code in this function.

	auto uLen = Math::Sqrt(Math::FAbs(lenSqr-dotSqr));
	auto test = mCone.GetCosAngle()*dot + mCone.GetSinAngle()*uLen;
	auto discr = test*test - lenSqr + rSqr;

    // compute point of intersection closest to vertex V
	auto t = test - Math::Sqrt(discr);
	auto B = diff - dot*mCone.GetAxis();
	auto tmp = mCone.GetSinAngle() / uLen;
	mPoint = t*(mCone.GetCosAngle()*mCone.GetAxis() + tmp*B);

	if (discr >= Math<Real>::sm_Zero && test >= Math<Real>::sm_Zero)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>
	::GetPoint() const
{
    return mPoint;
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_DETAIL_H