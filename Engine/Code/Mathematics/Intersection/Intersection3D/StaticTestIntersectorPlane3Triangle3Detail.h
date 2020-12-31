// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 13:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorPlane3Triangle3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Triangle3<Real>
	::StaticTestIntersectorPlane3Triangle3(const Plane3& plane,const Triangle3& triangle, Real epsilon)
	: m_Plane{ plane }, m_Triangle{ triangle }
{
    mEpsilon = (epsilon >= Math<Real>::GetValue(0) ? epsilon : Math<Real>::GetValue(0));
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Triangle3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorPlane3Triangle3<Real>
	::GetTriangle() const
{
    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Triangle3<Real>
	::Test()
{
    // Compute the signed distances from the vertices to the plane.
	auto zero = Math<Real>::GetValue(0);
    Real SD[3];
    for (auto i = 0; i < 3; ++i)
    {
        SD[i] = m_Plane.DistanceTo(m_Triangle.GetVertex()[i]);
        if (Math::FAbs(SD[i]) <= mEpsilon)
        {
            SD[i] = zero;
        }
    };

    // The triangle intersects the plane if not all vertices are on the
    // positive side of the plane and not all vertices are on the negative
    // side of the plane.
	if (!(SD[0] > zero && SD[1] > zero && SD[2] > zero)	&& !(SD[0] < zero && SD[1] < zero && SD[2] < zero))
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H