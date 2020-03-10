// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 09:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_DETAIL_H

#include "StaticFindIntersectorRay2Arc2.h"
#include "StaticFindIntersectorLine2Circle2.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::StaticFindIntersectorRay2Arc2(const Ray2& ray,const Arc2& arc)
	:mRay{ ray }, mArc{ arc }
{
	Find();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::GetArc() const
{
    return mArc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::Find()
{
    Real t[2];
    int quantity;
	auto intersects = StaticFindIntersectorLine2Circle2<Real>::Find(mRay.GetOrigin(),mRay.GetDirection(), mArc.GetCenter(), mArc.GetRadius(), quantity, t);

    mQuantity = 0;
    if (intersects)
    {
        // Reduce root count if line-circle intersections are not on ray.
        if (quantity == 1)
        {
            if (t[0] < Real{})
            {
                quantity = 0;
            }
        }
        else
        {
            if (t[1] < Real{})
            {
                quantity = 0;
            }
            else if (t[0] < Real{})
            {
                quantity = 1;
                t[0] = t[1];
            }
        }

        for (auto i = 0; i < quantity; ++i)
        {
			auto point = mRay.GetOrigin() + mRay.GetDirection()*t[i];
            if (mArc.Contains(point))
            {
                mPoint[mQuantity++] = point;
            }
        }
    }

	this->SetIntersectionType((mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty));
   
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorRay2Arc2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_DETAIL_H