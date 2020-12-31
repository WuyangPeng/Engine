// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorHalfspace3Triangle3.h"
#include "IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::StaticFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle)
	:m_Halfspace{ halfspace }, m_Triangle{ triangle }
{
	m_Quantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
	return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::Find()
{
	// Start with the triangle and then clip it against the plane.
	m_Quantity = 3;
	for (auto i = 0; i < 3; ++i)
	{
		m_Point[i] = m_Triangle.GetVertex()[i];
	}

	IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-m_Halfspace.GetNormal(), -m_Halfspace.GetConstant(), m_Quantity, m_Point);

	if (m_Quantity > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H