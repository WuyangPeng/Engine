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
	: mSphere0{ rkSphere0 }, mSphere1{ rkSphere1 }, mCircle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Math<Real>::sm_Zero }
{
	Find();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
    return mSphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
    return mSphere1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::Find()
{
    // Plane of intersection must have N as its normal.
	auto C1mC0 = mSphere1.GetCenter() - mSphere0.GetCenter();
	auto sqrLen = Vector3DTools::VectorMagnitudeSquared(C1mC0);
	auto r0 = mSphere0.GetRadius(), r1 = mSphere1.GetRadius();

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
        mContactPoint = mSphere0.GetCenter() + r0*C1mC0;
		mCircle = Circle3{ mContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::sm_Zero };
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
		mContactPoint = (Real{0.5})*(mSphere0.GetCenter() + mSphere1.GetCenter());
		mCircle = Circle3{ mContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::sm_Zero };

     
		this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> (rDif <= Math<Real>::sm_Zero ? IT_SPHERE0 : IT_SPHERE1));
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
      
        if (rDif <= Math<Real>::sm_Zero)
        {
            mContactPoint = mSphere1.GetCenter() + r1*C1mC0;
			this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> ( IT_SPHERE0_POINT));
        }
        else
        {
			mContactPoint = mSphere0.GetCenter() + r0*C1mC0;
			this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType> (IT_SPHERE1_POINT));
        }
         
		mCircle = Circle3(mContactPoint, Vector3D::sm_Zero, Vector3D::sm_Zero, C1mC0, Math<Real>::sm_Zero);

        return;
    }

    // Compute t for which the circle of intersection has center
    // K = C0 + t*(C1 - C0).
    auto t = (Real{0.5})*(static_cast<Real>(1) + rDif*rSum/sqrLen);

    // Center and radius of circle of intersection.
 

    // Compute N, U, and V for plane of circle.
    C1mC0.Normalize();
    
	auto vector3DOrthonormalBasis =	Vector3DTools::GenerateComplementBasis(C1mC0);
	mCircle = Circle3{ mSphere0.GetCenter() + t * C1mC0, vector3DOrthonormalBasis.GetUVector(),
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
    return mCircle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>
	::GetContactPoint() const
{
    return mContactPoint;
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H