// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "StaticFindIntersectorPlane3Plane3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::StaticFindIntersectorPlane3Plane3(const Plane3& rkPlane0, const Plane3& rkPlane1)
	:mPlane0{ rkPlane0 }, mPlane1{ rkPlane1 }, mIntrLine{ Vector3D::sm_Zero,Vector3D::sm_Zero }, mIntrPlane{}
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::GetPlane0() const
{
    return mPlane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::GetPlane1() const
{
    return mPlane1;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::Find()
{
    // If N0 and N1 are parallel, either the planes are parallel and separated
    // or the same plane.  In both cases, 'false' is returned.  Otherwise,
    // the intersection line is
    //   L(t) = t*Cross(N0,N1)/|Cross(N0,N1)| + c0*N0 + c1*N1
    // for some coefficients c0 and c1 and for t any real number (the line
    // parameter).  Taking dot products with the normals,
    //   d0 = Dot(N0,L) = c0*Dot(N0,N0) + c1*Dot(N0,N1) = c0 + c1*d
    //   d1 = Dot(N1,L) = c0*Dot(N0,N1) + c1*Dot(N1,N1) = c0*d + c1
    // where d = Dot(N0,N1).  These are two equations in two unknowns.  The
    // solution is
    //   c0 = (d0 - d*d1)/det
    //   c1 = (d1 - d*d0)/det
    // where det = 1 - d^2.

	auto dot = Vector3DTools::DotProduct(mPlane0.GetNormal(), mPlane1.GetNormal());
    if (Math::FAbs(dot) >= static_cast<Real>(1) - Math::GetZeroTolerance())
    {
        // The planes are parallel.  Check if they are coplanar.
        Real cDiff;
        if (dot >= Math<Real>::GetZero())
        {
            // Normals are in same direction, need to look at c0-c1.
			cDiff = mPlane0.GetConstant() - mPlane1.GetConstant();
        }
        else
        {
            // Normals are in opposite directions, need to look at c0+c1.
			cDiff = mPlane0.GetConstant() + mPlane1.GetConstant();
        }

        if (Math::FAbs(cDiff) < Math::GetZeroTolerance())
        {
            // Planes are coplanar.
			this->SetIntersectionType(IntersectionType::Plane);
            mIntrPlane = mPlane0;
            return;
        }

        // Planes are parallel, but distinct.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto invDet = (static_cast<Real>(1))/(static_cast<Real>(1) - dot*dot);
	auto c0 = (mPlane0.GetConstant() - dot*mPlane1.GetConstant())*invDet;
	auto c1 = (mPlane1.GetConstant() - dot*mPlane0.GetConstant())*invDet;
	this->SetIntersectionType(IntersectionType::Line);
	mIntrLine = Line3{ c0*mPlane0.GetNormal() + c1 * mPlane1.GetNormal(),Vector3DTools::UnitCrossProduct(mPlane0.GetNormal(),mPlane1.GetNormal()) };
}
 
template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::GetIntersectionLine() const
{
    return mIntrLine;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>
	::GetIntersectionPlane() const
{
    return mIntrPlane;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H