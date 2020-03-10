// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H

#include "StaticTestIntersectorRay3Box3.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Box3<Real>
	::StaticTestIntersectorRay3Box3(const Ray3& rkRay,const Box3& rkBox)
	: mRay{ rkRay }, mBox{ rkBox }
{
	Test();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Box3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorRay3Box3<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Box3<Real>
	::Test()
{
    Real WdU[3], AWdU[3], DdU[3], ADdU[3], AWxDdU[3], RHS;

	auto diff = mRay.GetOrigin() - mBox.GetCenter();

	WdU[0] = Vector3DTools::DotProduct(mRay.GetDirection(), mBox.GetAxis(0));
    AWdU[0] = Math::FAbs(WdU[0]);
	DdU[0] = Vector3DTools::DotProduct(diff, mBox.GetAxis(0));
    ADdU[0] = Math::FAbs(DdU[0]);
    if (ADdU[0] > mBox.GetExtent(0) && DdU[0]*WdU[0] >= Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	WdU[1] = Vector3DTools::DotProduct(mRay.GetDirection(), mBox.GetAxis(1));
    AWdU[1] = Math::FAbs(WdU[1]);
	DdU[1] = Vector3DTools::DotProduct(diff,mBox.GetAxis(1));
    ADdU[1] = Math::FAbs(DdU[1]);
	if (ADdU[1] > mBox.GetExtent(1) && DdU[1] * WdU[1] >= Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	WdU[2] = Vector3DTools::DotProduct(mRay.GetDirection(), mBox.GetAxis(2));
    AWdU[2] = Math::FAbs(WdU[2]);
	DdU[2] = Vector3DTools::DotProduct(diff, mBox.GetAxis(2));
    ADdU[2] = Math::FAbs(DdU[2]);
	if (ADdU[2] > mBox.GetExtent(2) && DdU[2] * WdU[2] >= Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	auto WxD = Vector3DTools::CrossProduct(mRay.GetDirection(),diff);

	AWxDdU[0] = Math::FAbs(Vector3DTools::DotProduct(WxD, mBox.GetAxis(0)));
	RHS = mBox.GetExtent(1)*AWdU[2] + mBox.GetExtent(2)*AWdU[1];
    if (AWxDdU[0] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	AWxDdU[1] = Math::FAbs(Vector3DTools::DotProduct(WxD, mBox.GetAxis(1)));
	RHS = mBox.GetExtent(0)*AWdU[2] + mBox.GetExtent(2) * AWdU[0];
    if (AWxDdU[1] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	AWxDdU[2] = Math::FAbs(Vector3DTools::DotProduct(WxD,mBox.GetAxis(2)));
	RHS = mBox.GetExtent(0)*AWdU[1] + mBox.GetExtent(1) * AWdU[0];
    if (AWxDdU[2] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	this->SetIntersectionType(IntersectionType::Point);
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H