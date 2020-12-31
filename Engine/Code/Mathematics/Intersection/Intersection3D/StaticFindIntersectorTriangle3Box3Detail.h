// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 10:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "StaticFindIntersectorTriangle3Box3.h"
#include "StaticFindIntersectorSegment3Box3.h" 
#include "IntersectorUtility3.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::StaticFindIntersectorTriangle3Box3 (const Triangle3& triangle,const Box3& box)
	:m_Triangle{ triangle }, m_Box{ box }
{
    m_Quantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetTriangle() const
{
    return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetBox() const
{
    return m_Box;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::Find()
{
    // Start with the triangle and clip it against each face of the box.
    m_Quantity = 3;
    for (auto i = 0; i < 3; ++i)
    {
        m_Point[i] = m_Triangle.GetVertex()[i];
    }

    for (auto dir = -1; dir <= 1; dir += 2)
    {
        for (auto side = 0; side < 3; ++side)
        {
			auto innerNormal = ((Real)dir)*m_Box.GetAxis(side);
			auto constant = Vector3DTools::DotProduct(innerNormal,m_Box.GetCenter()) - m_Box.GetExtent(side);
            ClipConvexPolygonAgainstPlane(innerNormal, constant,   m_Quantity, m_Point);
        }
    }

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
int Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H