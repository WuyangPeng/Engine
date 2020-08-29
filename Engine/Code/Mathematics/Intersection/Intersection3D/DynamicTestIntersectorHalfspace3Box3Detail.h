// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:45)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Box3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>
	::DynamicTestIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mBox{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>
	::Test()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	auto fmin = Math::GetValue(0);
	auto fmax = Math::GetValue(0);
	IntersectorAxis<Real>::GetProjection(mHalfspace.GetNormal(), mBox, fmin, fmax);

	auto mContactTime = this->GetContactTime();
	if (IntersectorAxis<Real>::Test(mHalfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, mHalfspace.GetConstant(), fmin, fmax, this->GetTMax(), mContactTime, tlast))
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H