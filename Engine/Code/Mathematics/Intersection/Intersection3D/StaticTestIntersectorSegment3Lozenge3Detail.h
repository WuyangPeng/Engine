// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorSegment3Lozenge3.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Rectangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>
	::StaticTestIntersectorSegment3Lozenge3( const Segment3& rkSegment, const Lozenge3& rkLozenge)
	: m_Segment{ rkSegment }, mLozenge{ rkLozenge }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>
	::GetLozenge() const
{
    return mLozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>
	::Test()
{
	auto distance = DistanceSegment3Rectangle3<Real>(m_Segment, mLozenge.GetRectangle()).Get().GetDistance();

	if (distance <= mLozenge.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H