// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H

#include "StaticTestIntersectorHalfspace3Box3.h"
#include "FindIntersectorAxis.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Box3<Real>
	::StaticTestIntersectorHalfspace3Box3(const Plane3& halfspace,const Box3& box)
	: m_Halfspace{ halfspace }, m_Box{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Box3<Real>
	::GetHalfspace() const
{
    return m_Halfspace;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorHalfspace3Box3<Real>
	::GetBox() const
{
    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Box3<Real>
	::Test()
{
    Real fmin, fmax;
    FindIntersectorAxis<Real>::GetProjection(m_Halfspace.GetNormal(), m_Box, fmin, fmax);
	if (fmin <= m_Halfspace.GetConstant())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}  

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H