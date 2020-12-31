// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Sphere3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>
	::DynamicTestIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Sphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>
	::GetSphere() const
{
	return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>
	::Test()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto distance = Vector3DTools::DotProduct(m_Halfspace.GetNormal(), m_Sphere.GetCenter());

	auto mContactTime = this->GetContactTime();
	if (FindIntersectorAxis<Real>::Test(m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), distance - m_Sphere.GetRadius(), distance + m_Sphere.GetRadius(), this->GetTMax(), mContactTime, tlast))
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

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H