// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:28)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Sphere3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::DynamicFindIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Sphere{ sphere }
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetSphere() const
{
	return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::Find()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto distance = Vector3DTools::DotProduct(m_Halfspace.GetNormal(), m_Sphere.GetCenter());

	auto mContactTime = this->GetContactTime();
	if (!FindIntersectorAxis<Real>::Test(m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), distance - m_Sphere.GetRadius(), distance + m_Sphere.GetRadius(), this->GetTMax(), mContactTime, tlast))
	{
		// Never intersecting.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	if (mContactTime == Math<Real>::GetZero())
	{
		// Intersecting now.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	m_Point = m_Sphere.GetCenter() + mContactTime * this->GetRhsVelocity() - m_Sphere.GetRadius()*m_Halfspace.GetNormal();

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Point);
	return;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>
	::GetPoint() const
{
	return m_Point;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H