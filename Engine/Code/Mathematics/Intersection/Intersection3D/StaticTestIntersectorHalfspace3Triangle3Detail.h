// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 11:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorHalfspace3Triangle3.h"
#include "FindIntersectorAxis.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::StaticTestIntersectorHalfspace3Triangle3 (const Plane3& halfspace, const Triangle3& triangle)
	:m_Halfspace{ halfspace }, m_Triangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
    return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::Test()
{
    Real fmin, fmax;
    FindIntersectorAxis<Real>::GetProjection(m_Halfspace.GetNormal(), m_Triangle, fmin, fmax);

	if (fmin <= m_Halfspace.GetConstant())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H