// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 16:31)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicFindIntersectorSegment3Box3.h"
#include "StaticFindIntersectorLine3Box3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::DynamicFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Segment{ segment }, m_Box{ box }
{
	m_Quantity = 0;
	m_Solid = solid;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetBox() const
{
	return m_Box;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::Find()
{
	m_Quantity = 0;
	this->SetIntersectionType(IntersectionType::Empty);

	// Get the endpoints of the segment.
	Vector3D segment[2]{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

	// Get the box velocity relative to the segment.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;

	auto i = 0;
	Vector3D axis;
	auto side = IntersectorConfiguration<Real>::NONE;
	IntersectorConfiguration<Real> segContact, boxContact;
	auto mContactTime = this->GetContactTime();
	// Test box normals.
	for (i = 0; i < 3; ++i)
	{
		axis = m_Box.GetAxis(i);
		if (!FindIntersectorAxis<Real>::Find(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast, side, segContact, boxContact))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// Test seg-direction cross box-edges.
	for (i = 0; i < 3; i++)
	{
		axis = Vector3DTools::CrossProduct(m_Box.GetAxis(i), m_Segment.GetDirection());
		if (!FindIntersectorAxis<Real>::Find(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast, side, segContact, boxContact))
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
		if (!FindIntersectorAxis<Real>::Find(axis, segment, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast, side, segContact, boxContact))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	if (mContactTime < Math<Real>::GetZero() || side == IntersectorConfiguration<Real>::NONE)
	{
		// intersecting now
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	FindContactSet<Real>(segment, m_Box, side, segContact, boxContact, this->GetLhsVelocity(), this->GetRhsVelocity(), mContactTime, m_Quantity, m_Point);

	SetContactTime(mContactTime);
	if (m_Quantity == 1)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Segment);
	}

	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H