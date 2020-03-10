// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/15 09:49)
#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorRay3Cylinder3.h"
#include "StaticFindIntersectorLine3Cylinder3.h"
 
template <typename Real>
Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::StaticFindIntersectorRay3Cylinder3(const Ray3& ray,const Cylinder3& cylinder)
	:mRay{ ray }, mCylinder{ cylinder }
{
	Find();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::GetCylinder() const
{
    return mCylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::Find()
{
    Real t[2];
	auto quantity = StaticFindIntersectorLine3Cylinder3<Real>::Find(mRay.GetOrigin(),mRay.GetDirection(), mCylinder, t);

    mQuantity = 0;
    for (auto i = 0; i < quantity; ++i)
    {
        if (t[i] >= Real{})
        {
			mPoint[mQuantity++] = mRay.GetOrigin() + t[i] * mRay.GetDirection();
        }
    }

    if (mQuantity == 2)
    {
		this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (mQuantity == 1)
    {
		this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
		this->SetIntersectionType(IntersectionType::Empty);
    }     
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_DETAIL_H