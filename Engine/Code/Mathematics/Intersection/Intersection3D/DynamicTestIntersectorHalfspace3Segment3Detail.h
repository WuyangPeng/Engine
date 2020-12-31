// Copyright (c) 2010-2020
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
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Segment{ segment }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>
	::Test()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	Vector3D segment[2]{ m_Segment.GetBeginPoint(),  m_Segment.GetEndPoint() };

	auto fmin = Math::GetValue(0);
	auto fmax = Math::GetValue(0);
	FindIntersectorAxis<Real>::GetProjection(m_Halfspace.GetNormal(), segment, fmin, fmax);

	auto mContactTime = Math::GetValue(0);
	if (FindIntersectorAxis<Real>::Test(m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), fmin, fmax, this->GetTMax(), mContactTime, tlast))
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