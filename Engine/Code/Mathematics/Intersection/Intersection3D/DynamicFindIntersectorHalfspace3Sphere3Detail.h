// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/13 13:00)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Sphere3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::DynamicFindIntersectorHalfspace3Sphere3 (const Plane3& halfspace,const Sphere3& sphere,Real tmax, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mSphere{ sphere }
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetHalfspace () const
{
    return mHalfspace;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetSphere () const
{
    return mSphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::Find ()
{
    SetContactTime(Real{});
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto distance = Vector3DTools::DotProduct(mHalfspace.GetNormal(),mSphere.GetCenter());

	auto mContactTime = this->GetContactTime();
    if (!IntersectorAxis<Real>::Test(mHalfspace.GetNormal(), relVelocity,-Math::sm_MaxReal, mHalfspace.GetConstant(),distance - mSphere.GetRadius(), distance + mSphere.GetRadius(), this->GetTMax(), mContactTime, tlast))
    {
        // Never intersecting.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (mContactTime == Real{})
    {
        // Intersecting now.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    mPoint = mSphere.GetCenter() + mContactTime* this->GetRhsVelocity() - mSphere.GetRadius()*mHalfspace.GetNormal();

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Point);
    return;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetPoint () const
{
    return mPoint;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H