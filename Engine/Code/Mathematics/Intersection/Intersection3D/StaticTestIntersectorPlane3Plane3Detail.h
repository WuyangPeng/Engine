// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 13:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "StaticTestIntersectorPlane3Plane3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Plane3<Real>::StaticTestIntersectorPlane3Plane3(const Plane3& rkPlane0, const Plane3& rkPlane1, const Real epsilon)
    : m_Plane0{ rkPlane0 }, m_Plane1{ rkPlane1 }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Plane3<Real>
	::GetPlane0() const
{
    return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Plane3<Real>
	::GetPlane1() const
{
    return m_Plane1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Plane3<Real>
	::Test()
{
    // If Cross(N0,N1) is zero, then either planes are parallel and separated
    // or the same plane.  In both cases, 'false' is returned.  Otherwise, the
    // planes intersect.  To avoid subtle differences in reporting between
    // Test() and Find(), the same parallel test is used.  Mathematically,
    //   |Cross(N0,N1)|^2 = Dot(N0,N0)*Dot(N1,N1)-Dot(N0,N1)^2
    //                    = 1 - Dot(N0,N1)^2
    // The last equality is true since planes are required to have unit-length
    // normal vectors.  The test |Cross(N0,N1)| = 0 is the same as
    // |Dot(N0,N1)| = 1.  I test the latter condition in Test() and Find().

	auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
	if (Math::FAbs(dot) < Math::GetValue(1) - Math::GetZeroTolerance())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
