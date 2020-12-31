// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:29)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Triangle3.h"
#include "FindIntersectorAxis.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::DynamicFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Triangle{ triangle }
{
	m_Quantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::Find()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	IntersectorConfiguration<Real> cfg;
	FindIntersectorAxis<Real>::GetConfiguration(m_Halfspace.GetNormal(), m_Triangle, cfg);

	Real mContactTime = this->GetContactTime();
	if (!FindIntersectorAxis<Real>::Test(m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), cfg.mMin, cfg.mMax, this->GetTMax(), mContactTime, tlast))
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

	// Tri on positive side (right).
	if (cfg.mMap == IntersectorConfiguration<Real>::m12 || cfg.mMap == IntersectorConfiguration<Real>::m111)
	{
		// Point intersection.
		m_Quantity = 1;
		m_Point[0] = m_Triangle.GetVertex()[cfg.mIndex[0]];
	}
	else if (cfg.mMap == IntersectorConfiguration<Real>::m21)
	{
		// Segment intersection.
		m_Quantity = 2;
		m_Point[0] = m_Triangle.GetVertex()[cfg.mIndex[0]];
		m_Point[1] = m_Triangle.GetVertex()[cfg.mIndex[1]];
	}
	else
	{
		// Face intersection.
		m_Quantity = 3;
		for (auto i = 0; i < 3; ++i)
		{
			m_Point[i] = m_Triangle.GetVertex()[i];
		}
	}

	// Adjust points to the correct place in time, as well.
	auto diff = mContactTime * this->GetRhsVelocity();
	for (auto i = 0; i < m_Quantity; ++i)
	{
		m_Point[i] += diff;
	}
	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Other);

	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H