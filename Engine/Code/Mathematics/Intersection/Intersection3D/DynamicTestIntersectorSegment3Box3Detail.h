// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicTestIntersectorSegment3Box3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::DynamicTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Segment{ segment }, m_Box{ box }
{
	m_Solid = solid;
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::GetBox() const
{
	return m_Box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::Test()
{
	// Get the endpoints of the segment.
	Vector3D segment[2]{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

	// Get the box velocity relative to the segment.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	auto mContactTime = Math<Real>::GetZero();
	auto tlast = Math::sm_MaxReal;

	auto i = 0;
	Vector3D axis;

	// Test box normals.
	for (i = 0; i < 3; ++i)
	{
		axis = m_Box.GetAxis(i);
		if (!FindIntersectorAxis<Real>::Test(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// Test seg-direction cross box-edges.
	for (i = 0; i < 3; ++i)
	{
		axis = Vector3DTools::CrossProduct(m_Box.GetAxis(i), m_Segment.GetDirection());
		if (!FindIntersectorAxis<Real>::Test(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// Test velocity cross box-faces.
	for (i = 0; i < 3; i++)
	{
		axis = Vector3DTools::CrossProduct(relVelocity, m_Box.GetAxis(i));
		if (!FindIntersectorAxis<Real>::Test(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Point);
	return;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H