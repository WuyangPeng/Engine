// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:45)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Segment3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::DynamicTestIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mSegment{ segment }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::Test()
{
	SetContactTime(Math<Real>::sm_Zero);
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	Vector3D segment[2]{ mSegment.GetBeginPoint(),  mSegment.GetEndPoint() };

	auto fmin = Math::sm_Zero;
	auto fmax = Math::sm_Zero;
	IntersectorAxis<Real>::GetProjection(mHalfspace.GetNormal(), segment, fmin, fmax);

	auto mContactTime = Math::sm_Zero;
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

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H