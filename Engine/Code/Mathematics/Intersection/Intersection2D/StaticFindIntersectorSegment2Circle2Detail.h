// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_DETAIL_H
 
#include "StaticFindIntersectorSegment2Circle2.h"
#include "StaticFindIntersectorLine2Circle2.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::StaticFindIntersectorSegment2Circle2(const Segment2& segment,const Circle2& circle)
	: mSegment{ segment }, mCircle{ circle }
{
	Find();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::GetCircle() const
{
    return mCircle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::Find()
{
    Real t[2];
	auto intersects = StaticFindIntersectorLine2Circle2<Real>::Find(mSegment.GetCenterPoint(),mSegment.GetDirection(), mCircle.GetCenter(), mCircle.GetRadius(), mQuantity, t);

    if (intersects)
    {
        // Reduce root count if line-circle intersections are not on segment.
        if (mQuantity == 1)
		{
			if (Math::FAbs(t[0]) > mSegment.GetExtent())
            {
                mQuantity = 0;
            }
        }
        else
        {
			if (t[1] < -mSegment.GetExtent() || t[0] > mSegment.GetExtent())
            {
                mQuantity = 0;
            }
            else
            {
				if (t[1] <= mSegment.GetExtent())
                {
					if (t[0] < -mSegment.GetExtent())
                    {
                        mQuantity = 1;
                        t[0] = t[1];
                    }
                }
                else
                {
					mQuantity = (t[0] >= -mSegment.GetExtent() ? 1 : 0);
                }
            }
        }

        for (int i = 0; i < mQuantity; ++i)
        {
            mPoint[i] = mSegment.GetCenterPoint() + t[i]*mSegment.GetDirection();
        }
    }

	this->SetIntersectionType(mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_DETAIL_H