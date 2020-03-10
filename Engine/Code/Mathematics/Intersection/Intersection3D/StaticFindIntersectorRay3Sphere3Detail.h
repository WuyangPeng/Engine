// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/15 09:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorRay3Sphere3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::StaticFindIntersectorRay3Sphere3 (const Ray3& ray,const Sphere3& sphere)
	: mRay{ ray }, mSphere{ sphere }
{
    mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::Find()
{
    auto diff = mRay.GetOrigin() - mSphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - mSphere.GetRadius()*mSphere.GetRadius();
    Real a1, discr, root;
    if (a0 <= Real{})
    {
        // P is inside the sphere
		a1 = Vector3DTools::DotProduct(mRay.GetDirection(),diff);
        discr = a1*a1 - a0;
        root = Math::Sqrt(discr);
        mRayParameter[0] = -a1 + root;
        mPoint[0] = mRay.GetOrigin() + mRayParameter[0]*mRay.GetDirection();
        mQuantity = 1;
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }
    // else: P is outside the sphere

	a1 = Vector3DTools::DotProduct(mRay.GetDirection(),diff);
    if (a1 >= Real{0.0})
    {
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    discr = a1*a1 - a0;
    if (discr < Real{0.0})
    {
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (discr >= Math::sm_ZeroTolerance)
    {
        root = Math::Sqrt(discr);
        mRayParameter[0] = -a1 - root;
        mRayParameter[1] = -a1 + root;
        mPoint[0] = mRay.GetOrigin() + mRayParameter[0]*mRay.GetDirection();
        mPoint[1] = mRay.GetOrigin() + mRayParameter[1]*mRay.GetDirection();
        mQuantity = 2;
		this->SetIntersectionType(IntersectionType::Segment);
    }
    else
    {
        mRayParameter[0] = -a1;
        mPoint[0] = mRay.GetOrigin() + mRayParameter[0]*mRay.GetDirection();
        mQuantity = 1;
		this->SetIntersectionType(IntersectionType::Point);
    }   
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Sphere3<Real>
	::GetRayParameter(int i) const
{
    return mRayParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_DETAIL_H