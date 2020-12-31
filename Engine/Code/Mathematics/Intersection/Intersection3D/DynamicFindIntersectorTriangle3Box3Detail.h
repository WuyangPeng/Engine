// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "DynamicFindIntersectorTriangle3Box3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::DynamicFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Triangle{ triangle }, m_Box{ box }
{
	m_Quantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::GetBox() const
{
	return m_Box;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::Find()
{
	auto tmax = this->GetTMax();
	auto velocity0 = this->GetLhsVelocity();
	auto velocity1 = this->GetRhsVelocity();

	// Process as if triangle is stationary, box is moving.
	auto relVelocity = velocity1 - velocity0;

	SetContactTime(Math::GetValue(0));
	auto tlast = Math::sm_MaxReal;

	auto side = IntersectorConfiguration<Real>::NONE;
	IntersectorConfiguration<Real> triContact, boxContact;

	// Test tri-normal.
	Vector3D edge[3]{ m_Triangle.GetVertex()[1] - m_Triangle.GetVertex()[0],
					  m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[1],
					  m_Triangle.GetVertex()[0] - m_Triangle.GetVertex()[2] };

	auto triNorm = Vector3DTools::CrossProduct(edge[0], edge[1]);
	auto mContactTime = this->GetContactTime();
	if (!FindIntersectorAxis<Real>::Find(triNorm, m_Triangle, m_Box, relVelocity, tmax, mContactTime, tlast, side, triContact, boxContact))
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	Vector3D axis;
	auto coplanar = -1; // triangle coplanar to none of the box normals
	auto i0 = 0;
	for (i0 = 0; i0 < 3; ++i0)
	{
		axis = m_Box.GetAxis(i0);
		if (!FindIntersectorAxis<Real>::Find(axis, m_Triangle, m_Box, relVelocity, tmax, mContactTime, tlast, side, triContact, boxContact))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}

		// Test if axis is parallel to triangle normal.  The test is:
		// sin(Angle(normal,axis)) < epsilon
		auto NdA = Vector3DTools::DotProduct(triNorm, axis);
		auto NdN = Vector3DTools::VectorMagnitudeSquared(triNorm);
		auto AdA = Vector3DTools::VectorMagnitudeSquared(axis);
		auto sn = Math::Sqrt(Math::FAbs(Math::GetValue(1) - NdA * NdA / (NdN*AdA)));
		if (sn < Math::GetZeroTolerance())
		{
			coplanar = i0;
		}
	}

	if (coplanar == -1)
	{
		// Test triedges cross boxfaces.
		for (i0 = 0; i0 < 3; ++i0)
		{
			for (auto i1 = 0; i1 < 3; ++i1)
			{
				axis = Vector3DTools::CrossProduct(edge[i0], m_Box.GetAxis(i1));
				if (!FindIntersectorAxis<Real>::Find(axis, m_Triangle, m_Box, relVelocity, tmax, mContactTime, tlast, side, triContact, boxContact))
				{
					SetContactTime(mContactTime);
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
			}
		}
	}
	else
	{
		// Test triedges cross coplanar box axis.
		for (i0 = 0; i0 < 3; ++i0)
		{
			axis = Vector3DTools::CrossProduct(edge[i0], triNorm);
			if (!FindIntersectorAxis<Real>::Find(axis, m_Triangle, m_Box, relVelocity, tmax, mContactTime, tlast, side, triContact, boxContact))
			{
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}

	// Test velocity cross box faces.
	for (i0 = 0; i0 < 3; ++i0)
	{
		axis = Vector3DTools::CrossProduct(relVelocity, m_Box.GetAxis(i0));
		if (!FindIntersectorAxis<Real>::Find(axis, m_Triangle, m_Box, relVelocity, tmax, mContactTime, tlast, side, triContact, boxContact))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	if (mContactTime < Math::GetValue(0) || side == IntersectorConfiguration<Real>::NONE)
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	FindContactSet<Real>(m_Triangle, m_Box, side, triContact, boxContact, velocity0, velocity1, mContactTime, m_Quantity, m_Point);

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Other);
	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorTriangle3Box3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H