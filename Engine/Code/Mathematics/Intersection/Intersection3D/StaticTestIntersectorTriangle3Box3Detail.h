// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "StaticTestIntersectorTriangle3Box3.h"
#include "StaticTestIntersectorSegment3Box3.h"
#include "FindIntersectorAxis.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Box3<Real>::StaticTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon)
    : m_Triangle{ triangle }, m_Box{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Box3<Real>
	::GetTriangle() const
{
    return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorTriangle3Box3<Real>
	::GetBox() const
{
    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Box3<Real>
	::Test()
{
    Real min0, max0, min1, max1;
    Vector3D D, edge[3];

    // Test direction of triangle normal.
	edge[0] = m_Triangle.GetVertex()[1] - m_Triangle.GetVertex()[0];
	edge[1] = m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[0];
	D = Vector3DTools::CrossProduct(edge[0],edge[1]);
	min0 = Vector3DTools::DotProduct(D,m_Triangle.GetVertex()[0]);
    max0 = min0;
    FindIntersectorAxis<Real>::GetProjection(D, m_Box, min1, max1);
    if (max1 < min0 || max0 < min1)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // Test direction of box faces.
    for (int i = 0; i < 3; ++i)
    {
        D = m_Box.GetAxis(i);
        FindIntersectorAxis<Real>::GetProjection(D, m_Triangle, min0, max0);
		auto DdC = Vector3DTools::DotProduct(D,m_Box.GetCenter());
        min1 = DdC - m_Box.GetExtent(i);
		max1 = DdC + m_Box.GetExtent(i);
        if (max1 < min0 || max0 < min1)
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // Test direction of triangle-box edge cross products.
    edge[2] = edge[1] - edge[0];
    for (int i0 = 0; i0 < 3; ++i0)
    {
        for (int i1 = 0; i1 < 3; ++i1)
        {
			D = Vector3DTools::CrossProduct(edge[i0],m_Box.GetAxis(i1));
            FindIntersectorAxis<Real>::GetProjection(D, m_Triangle, min0, max0);
            FindIntersectorAxis<Real>::GetProjection(D, m_Box, min1, max1);
            if (max1 < min0 || max0 < min1)
            {
				this->SetIntersectionType(IntersectionType::Empty);
				return;
            }
        }
    }

	this->SetIntersectionType(IntersectionType::Other);
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H