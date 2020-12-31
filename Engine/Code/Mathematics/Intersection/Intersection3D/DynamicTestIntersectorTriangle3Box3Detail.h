// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:49)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "DynamicTestIntersectorTriangle3Box3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Box3<Real>
	::DynamicTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Triangle{ triangle }, m_Box{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Box3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorTriangle3Box3<Real>
	::GetBox() const
{
	return m_Box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Box3<Real>
	::Test()
{
	// Process as if triangle is stationary, box is moving.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto mContactTime = Math<Real>::GetZero();
	auto tlast = Math::sm_MaxReal;

	// Test direction of triangle normal.
	Vector3D edge[3]{ m_Triangle.GetVertex()[1] - m_Triangle.GetVertex()[0],
					  m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[0],
					  m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[1] };
	auto D = Vector3DTools::CrossProduct(edge[0], edge[1]);
	if (!FindIntersectorAxis<Real>::Test(D, m_Triangle, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Test direction of box faces.
	for (auto i = 0; i < 3; ++i)
	{
		D = m_Box.GetAxis(i);
		if (!FindIntersectorAxis<Real>::Test(D, m_Triangle, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	// Test direction of triangle-box edge cross products.
	for (auto i0 = 0; i0 < 3; ++i0)
	{
		for (auto i1 = 0; i1 < 3; ++i1)
		{
			D = Vector3DTools::CrossProduct(edge[i0], m_Box.GetAxis(i1));
			if (!FindIntersectorAxis<Real>::Test(D, m_Triangle, m_Box, relVelocity, this->GetTMax(), mContactTime, tlast))
			{
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}
	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Other);
	return;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H