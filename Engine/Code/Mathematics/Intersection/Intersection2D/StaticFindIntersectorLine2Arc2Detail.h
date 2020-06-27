// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_DETAIL_H

#include "StaticFindIntersectorLine2Arc2.h"
#include "StaticFindIntersectorLine2Circle2.h" 

template <typename Real>
Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::StaticFindIntersectorLine2Arc2(const Line2& rkLine, const Arc2& rkArc)
	:mLine{ rkLine }, mArc{ rkArc }
{
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::GetArc() const
{
	return mArc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::Find()
{
	Real t[2]{};
	auto quantity = 0;
	auto intersects = StaticFindIntersectorLine2Circle2<Real>::Find(mLine.GetOrigin(), mLine.GetDirection(), mArc.GetCenter(), mArc.GetRadius(), quantity, t);

	mQuantity = 0;
	if (intersects)
	{
		for (auto i = 0; i < quantity; ++i)
		{
			auto point = mLine.GetOrigin() + mLine.GetDirection()*t[i];
			if (mArc.Contains(point))
			{
				mPoint[mQuantity++] = point;
			}
		}
	}

	this->SetIntersectionType(mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorLine2Arc2<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_DETAIL_H