// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:40)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorSegment3Capsule3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::StaticTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Sphere{ sphere }
{
     ZeroThreshold = Math::GetZeroTolerance();
	 Test();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Sphere3<Real>	
	::Test()
{
	auto diff = m_Segment.GetCenterPoint() - m_Sphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - m_Sphere.GetRadius()*m_Sphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(),diff);
	auto discr = a1*a1 - a0;
    if (discr < Math::GetValue(0))
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto tmp0 = m_Segment.GetExtent()*m_Segment.GetExtent() + a0;
	auto tmp1 = (Math::GetValue(2))*a1*m_Segment.GetExtent();
	auto qm = tmp0 - tmp1;
	auto qp = tmp0 + tmp1;
    if (qm*qp <= Math::GetValue(0))
    {
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

	if (qm > Math::GetValue(0) && Math::FAbs(a1) < m_Segment.GetExtent())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H