// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H

#include "StaticFindIntersectorSegment2Box2.h" 
#include "StaticFindIntersectorLine2Box2.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::StaticFindIntersectorSegment2Box2(const Segment2& segment,const Box2& box, bool solid)
	:mSegment{ segment }, mBox{ box }
{
    mSolid = solid;

	Find();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::Find()
{
	auto t0 = -mSegment.GetExtent(), t1 = mSegment.GetExtent();
	int mIntersectionType = 0;
	StaticFindIntersectorLine2Box2<Real>::DoClipping(t0, t1, mSegment.GetCenterPoint(), mSegment.GetDirection(), mBox, mSolid, mQuantity, mPoint,  mIntersectionType);
	SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>(mIntersectionType));
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H