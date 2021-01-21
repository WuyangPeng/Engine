// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:20)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorLine3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Capsule3<Real>::StaticTestIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule, const Real epsilon)
    : m_Line{ line }, m_Capsule{ capsule }
{
	Test();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Capsule3<Real>::GetLine() const noexcept
{
    return m_Line;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorLine3Capsule3<Real>::GetCapsule() const noexcept
{
    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Capsule3<Real>
	::Test()
{
	auto distance = DistanceLine3Segment3<Real>(m_Line, m_Capsule.GetSegment()).Get().GetDistance();
	if (distance <= m_Capsule.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
