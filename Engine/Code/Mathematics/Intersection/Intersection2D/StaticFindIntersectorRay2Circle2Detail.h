// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 09:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_DETAIL_H

#include "StaticFindIntersectorRay2Circle2.h"
#include "StaticFindIntersectorLine2Circle2.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::StaticFindIntersectorRay2Circle2(const Ray2& ray,const Circle2& circle)
	: mRay{ ray }, mCircle{ circle }
{
	Find();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::GetCircle() const
{
    return mCircle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::Find()
{
    Real t[2];
	auto intersects = StaticFindIntersectorLine2Circle2<Real>::Find(mRay.GetOrigin(),mRay.GetDirection(), mCircle.GetCenter(), mCircle.GetRadius(), mQuantity, t);

    if (intersects)
    {
        // Reduce root count if line-circle intersections are not on ray.
        if (mQuantity == 1)
        {
            if (t[0] < Real{})
            {
                mQuantity = 0;
            }
        }
        else
        {
            if (t[1] < Real{})
            {
                mQuantity = 0;
            }
            else if (t[0] < Real{})
            {
                mQuantity = 1;
                t[0] = t[1];
            }
        }

        for (int i = 0; i < mQuantity; ++i)
        {
            mPoint[i] = mRay.GetOrigin() + t[i]*mRay.GetDirection();
        }
    }

	this->SetIntersectionType(mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty);
   
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorRay2Circle2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_DETAIL_H