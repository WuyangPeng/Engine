// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 13:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorSegment3Triangle3.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::StaticTestIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon)
    : m_Segment{ segment }, m_Triangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Triangle3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorSegment3Triangle3<Real>
	::GetTriangle() const
{
    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Triangle3<Real>
	::Test()
{
    // Compute the offset origin, edges, and normal.
    auto diff = m_Segment.GetCenterPoint() - m_Triangle.GetVertex()[0];
	auto edge1 = m_Triangle.GetVertex()[1] - m_Triangle.GetVertex()[0];
	auto edge2 = m_Triangle.GetVertex()[2] - m_Triangle.GetVertex()[0];
	auto normal = Vector3DTools::CrossProduct(edge1,edge2);

    // Solve Q + t*D = b1*E1 + b2*E2 (Q = diff, D = segment direction,
    // E1 = edge1, E2 = edge2, N = Cross(E1,E2)) by
    //   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
    //   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
    //   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
	auto DdN = Vector3DTools::DotProduct(m_Segment.GetDirection(),normal);
    Real sign;
    if (DdN > Math::GetZeroTolerance())
    {
        sign = Math::GetValue(1);
    }
    else if (DdN < -Math::GetZeroTolerance())
    {
        sign = (Real)-1;
        DdN = -DdN;
    }
    else
    {
        // Segment and triangle are parallel, call it a "no intersection"
        // even if the segment does intersect.
		this->SetIntersectionType(IntersectionType::Empty);
      
        return;
    }

	auto DdQxE2 = sign*Vector3DTools::DotProduct(m_Segment.GetDirection(), Vector3DTools::CrossProduct(diff,edge2));
    if (DdQxE2 >= Math<Real>::GetValue(0))
    {
		auto DdE1xQ = sign*Vector3DTools::DotProduct(m_Segment.GetDirection(), Vector3DTools::CrossProduct(edge1,diff));
        if (DdE1xQ >= Math<Real>::GetValue(0))
        {
            if (DdQxE2 + DdE1xQ <= DdN)
            {
                // Line intersects triangle, check if segment does.
				auto QdN = -sign*Vector3DTools::DotProduct(diff,normal);
				auto extDdN = m_Segment.GetExtent()*DdN;
                if (-extDdN <= QdN && QdN <= extDdN)
                {
                    // Segment intersects triangle.
					this->SetIntersectionType(IntersectionType::Point);
               
                    return;
                }
                // else: |t| > extent, no intersection
            }
            // else: b1+b2 > 1, no intersection
        }
        // else: b2 < 0, no intersection
    }
    // else: b1 < 0, no intersection

	this->SetIntersectionType(IntersectionType::Empty);
   
    return;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H