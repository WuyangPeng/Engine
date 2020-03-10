// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:12)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H
 
#include "StaticFindIntersectorSegment2Triangle2.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"
#include "StaticFindIntersectorLine2Triangle2.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::StaticFindIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle)
	: mSegment{ segment }, mTriangle{ triangle }
{
	Find();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::GetTriangle() const
{
    return mTriangle;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::Find()
{
    Real dist[3];
    int sign[3], positive, negative, zero;
	StaticFindIntersectorLine2Triangle2<Real>::TriangleLineRelations(mSegment.GetCenterPoint(),mSegment.GetDirection(), mTriangle, dist, sign, positive, negative,zero);

    if (positive == 3 || negative == 3)
    {
        // No intersections.
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        Real param[2];
		StaticFindIntersectorLine2Triangle2<Real>::GetInterval(mSegment.GetCenterPoint(),mSegment.GetDirection(), mTriangle, dist, sign, param);

		StaticFindIntersector1<Real> intr{ param[0], param[1],-mSegment.GetExtent(), +mSegment.GetExtent() };   

        mQuantity = intr.GetNumIntersections();
        if (mQuantity == 2)
        {
            // Segment intersection.
			this->SetIntersectionType(IntersectionType::Segment);
            mPoint[0] = mSegment.GetCenterPoint() + intr.GetIntersection(0)*mSegment.GetDirection();
			mPoint[1] = mSegment.GetCenterPoint() + intr.GetIntersection(1)*mSegment.GetDirection();
        }
        else if (mQuantity == 1)
        {
            // Point intersection.
             
			this->SetIntersectionType(IntersectionType::Point);
			mPoint[0] = mSegment.GetCenterPoint() + intr.GetIntersection(0)*mSegment.GetDirection();
        }
        else
        {
            // No intersections.
			this->SetIntersectionType(IntersectionType::Empty);            
        }
    }
	 
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H