// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:22)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorLine3Lozenge3.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Rectangle3.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::StaticTestIntersectorLine3Lozenge3(const Line3& line, const Lozenge3& lozenge, const Real epsilon)
    : m_Line{ line }, mLozenge{ lozenge }
{
	Test();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Lozenge3<Real>
	::GetLine() const
{
    return m_Line;
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLine3Lozenge3<Real>
	::GetLozenge() const
{
    return mLozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Lozenge3<Real>
	::Test()
{
    auto distance = DistanceLine3Rectangle3<Real>(m_Line, mLozenge.GetRectangle()).Get().GetDistance();

	if (distance <= mLozenge.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H