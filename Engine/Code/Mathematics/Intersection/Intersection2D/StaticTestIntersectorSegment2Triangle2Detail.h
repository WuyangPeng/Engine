// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorSegment2Triangle2.h"
#include "StaticTestIntersectorLine2Triangle2.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h" 
 
template <typename Real>
Mathematics::StaticTestIntersectorSegment2Triangle2<Real>
	::StaticTestIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle)
	: mSegment{ segment }, mTriangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorSegment2Triangle2<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorSegment2Triangle2<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment2Triangle2<Real>
	::Test()
{
    Real dist[3];
    int sign[3], positive, negative, zero;
    StaticFindIntersectorLine2Triangle2<Real>::TriangleLineRelations(mSegment.GetCenterPoint(),mSegment.GetDirection(), mTriangle, dist, sign, positive, negative,zero);

    if (positive == 3 || negative == 3)
    {
		this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        Real param[2];
		StaticFindIntersectorLine2Triangle2<Real>::GetInterval(mSegment.GetCenterPoint(),mSegment.GetDirection(), mTriangle, dist, sign, param);

        StaticFindIntersector1<Real> intr(param[0], param[1], -mSegment.GetExtent(), +mSegment.GetExtent()); 

		auto mQuantity = intr.GetNumIntersections();
        if (mQuantity == 2)
        {
			this->SetIntersectionType(IntersectionType::Segment);
        }
        else if (mQuantity == 1)
        {
			this->SetIntersectionType(IntersectionType::Point);
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H