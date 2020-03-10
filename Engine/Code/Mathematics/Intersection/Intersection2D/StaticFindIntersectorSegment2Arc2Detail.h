// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_DETAIL_H
 
#include "StaticFindIntersectorSegment2Arc2.h"
#include "StaticFindIntersectorLine2Circle2.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::StaticFindIntersectorSegment2Arc2(const Segment2& segment,const Arc2& arc)
	: mSegment{ segment }, mArc{ arc }
{
	Find();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::GetArc() const
{
    return mArc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::Find()
{
    Real t[2];
    int quantity;
	auto intersects = StaticFindIntersectorLine2Circle2<Real>::Find(mSegment.GetCenterPoint(),mSegment.GetDirection(), mArc.GetCenter(), mArc.GetRadius(), quantity, t);

    mQuantity = 0;
    if (intersects)
    {
        // Reduce root count if line-circle intersections are not on segment.
        if (quantity == 1)
        {
            if (Math::FAbs(t[0]) > mSegment.GetExtent())
            {
                quantity = 0;
            }
        }
        else
        {
			if (t[1] < -mSegment.GetExtent() || t[0] > mSegment.GetExtent())
            {
                quantity = 0;
            }
            else
            {
				if (t[1] <= mSegment.GetExtent())
                {
					if (t[0] < -mSegment.GetExtent())
                    {
                        quantity = 1;
                        t[0] = t[1];
                    }
                }
                else
                {
					quantity = (t[0] >= -mSegment.GetExtent() ? 1 : 0);
                }
            }
        }

        for (auto i = 0; i < quantity; ++i)
        {
			auto point = mSegment.GetCenterPoint() + mSegment.GetDirection()*t[i];

            if (mArc.Contains(point))
            {
                mPoint[mQuantity++] = point;
            }
        }
    }

	this->SetIntersectionType(mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_DETAIL_H