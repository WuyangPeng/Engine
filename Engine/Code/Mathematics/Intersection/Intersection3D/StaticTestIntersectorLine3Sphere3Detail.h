// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:24)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorLine3Sphere3.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Sphere3<Real>
	::StaticTestIntersectorLine3Sphere3 (const Line3& line,const Sphere3& sphere)
	: mLine{ line }, m_Sphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Sphere3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorLine3Sphere3<Real>
	::GetSphere() const
{
    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Sphere3<Real>
	::Test()
{
    auto diff = mLine.GetOrigin() - m_Sphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - m_Sphere.GetRadius()*m_Sphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(mLine.GetDirection(),diff);
	auto discr = a1*a1 - a0;
	if (discr >= Math<Real>::GetZero())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_DETAIL_H