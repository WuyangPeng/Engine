// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Triangle3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>
	::DynamicTestIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Triangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>
	::Test()
{
	auto mContactTime = Math<Real>::GetZero();
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	auto fmin = Math::GetValue(0);
	auto fmax = Math::GetValue(0);
	FindIntersectorAxis<Real>::GetProjection(m_Halfspace.GetNormal(), m_Triangle, fmin, fmax);

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

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H