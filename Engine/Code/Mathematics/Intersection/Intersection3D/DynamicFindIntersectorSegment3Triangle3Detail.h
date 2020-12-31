// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorSegment3Triangle3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::DynamicFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Segment{ segment }, m_Triangle{ triangle }
{
	m_Quantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetSegmentParameter() const
{
	return m_SegmentParameter;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetTriBary0() const
{
	return m_TriBary0;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetTriBary1() const
{
	return m_TriBary1;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetTriBary2() const
{
	return m_TriBary2;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::Find()
{
	auto tmax = this->GetTMax();
	auto velocity0 = this->GetLhsVelocity();
	auto velocity1 = this->GetRhsVelocity();

	m_Quantity = 0;
	this->SetIntersectionType(IntersectionType::Empty);

	// Get the endpoints of the segment.
	Vector3D segment[2]{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

	// Get the triangle edges.
	auto edge0 = m_Triangle.GetVertex()[1] - m_Triangle.GetVertex()[0];
	auto edge1 = m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[0];

	// Get the triangle velocity relative to the segment.
	auto relVelocity = velocity1 - velocity0;

	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;

	// Test tri-normal.
	auto normV = Vector3DTools::CrossProduct(edge0, edge1);
	IntersectorConfiguration<Real> segContact, triContact;
	auto side = 0;
	auto mContactTime = this->GetContactTime();
	if (!FindIntersectorAxis<Real>::Find(normV, segment, m_Triangle, relVelocity, tmax, mContactTime, tlast, side, segContact, triContact))
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Test whether the segment is parallel to the triangle, effectively the
	// test:  sin(Angle(NormV,DirU)) > 1-epsilon
	auto dirU = segment[1] - segment[0];
	auto normU = Vector3DTools::CrossProduct(normV, dirU);
	auto dirSqrLen = Vector3DTools::VectorMagnitudeSquared(dirU);
	auto norUSqrLen = Vector3DTools::VectorMagnitudeSquared(normU);
	auto norVSqrLen = Vector3DTools::VectorMagnitudeSquared(normV);
	auto oneMinusEpsilon = Math::GetValue(1) - Math::GetZeroTolerance();

	auto i0 = 0;
	auto i1 = 0;
	Vector3D axis;

	if (norUSqrLen > oneMinusEpsilon*norVSqrLen*dirSqrLen)  // parallel
	{
		// Find tri-normal cross seg-direction.
		if (!FindIntersectorAxis<Real>::Find(normU, segment, m_Triangle, relVelocity, tmax, mContactTime, tlast, side, segContact, triContact))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}

		// Find tri-normal cross tri-edges.
		for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
		{
			axis = Vector3DTools::CrossProduct(normV, (m_Triangle.GetVertex()[i1] - m_Triangle.GetVertex()[i0]));

			if (!FindIntersectorAxis<Real>::Find(axis, segment, m_Triangle, relVelocity, tmax, mContactTime, tlast, side, segContact, triContact))
			{
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}
	else
	{
		// Test seg-direction cross tri-edges.
		for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
		{
			axis = Vector3DTools::CrossProduct(dirU, (m_Triangle.GetVertex()[i1] - m_Triangle.GetVertex()[i0]));

			if (!FindIntersectorAxis<Real>::Find(axis, segment, m_Triangle, relVelocity, tmax, mContactTime, tlast, side, segContact, triContact))
			{
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}

	if (mContactTime < Math<Real>::GetZero())
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	FindContactSet<Real>(segment, m_Triangle, side, segContact, triContact, velocity0, velocity1, mContactTime, m_Quantity, m_Point);
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
int Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H