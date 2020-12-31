// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:28)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Segment3.h"
#include "FindIntersectorAxis.h"
#include "IntersectorConfiguration.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::DynamicFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Halfspace{ halfspace }, m_Segment{ segment }
{
	m_Quantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::Find()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	Vector3D segment[2]{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

	IntersectorConfiguration<Real> cfg;
	FindIntersectorAxis<Real>::GetConfiguration(m_Halfspace.GetNormal(), segment, cfg);

	auto mContactTime = this->GetContactTime();
	if (!FindIntersectorAxis<Real>::Test(m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), cfg.mMin, cfg.mMax, this->GetTMax(), mContactTime, tlast))
	{
		// Never intersecting.
		this->SetIntersectionType(IntersectionType::Empty);
		SetContactTime(mContactTime);
		return;
	}

	if (mContactTime == Math<Real>::GetZero())
	{
		// Intersecting now.
		this->SetIntersectionType(IntersectionType::Empty);
		SetContactTime(mContactTime);
		return;
	}

	// Line on positive side (right).
	if (cfg.mMap == IntersectorConfiguration<Real>::m11)
	{
		m_Quantity = 1;
		m_Point[0] = segment[cfg.mIndex[0]];
	}
	else // cfg.mMap == IntersectorConfiguration<Real>::m2
	{
		m_Quantity = 2;
		m_Point[0] = segment[cfg.mIndex[0]];
		m_Point[1] = segment[cfg.mIndex[1]];
	}

	// Adjust points to the correct place in time, as well.
	auto diff = mContactTime * this->GetRhsVelocity();
	for (auto i = 0; i < m_Quantity; ++i)
	{
		m_Point[i] += diff;
	}
	this->SetIntersectionType(IntersectionType::Other);
	SetContactTime(mContactTime);
	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H