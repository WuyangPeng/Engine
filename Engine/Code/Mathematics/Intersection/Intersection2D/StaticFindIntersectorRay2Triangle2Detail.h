// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorRay2Triangle2.h"
#include "StaticFindIntersectorLine2Triangle2.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::StaticFindIntersectorRay2Triangle2(const Ray2& ray,const Triangle2& triangle)
	: mRay{ ray }, mTriangle{ triangle }
{
	Find();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::Find()
{
    Real dist[3];
    int sign[3], positive, negative, zero;
	StaticFindIntersectorLine2Triangle2<Real>::TriangleLineRelations(mRay.GetOrigin(),mRay.GetDirection(), mTriangle, dist, sign, positive, negative, zero);

    if (positive == 3 || negative == 3)
    {
        // No intersections.
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        Real param[2];
		StaticFindIntersectorLine2Triangle2<Real>::GetInterval(mRay.GetOrigin(),mRay.GetDirection(), mTriangle, dist, sign, param);

		StaticFindIntersector1<Real> intr{ param[0], param[1], Real{},Math::sm_MaxReal };

        mQuantity = intr.GetNumIntersections();
        if (mQuantity == 2)
        {
            // Segment intersection.
       
			this->SetIntersectionType(IntersectionType::Segment);
			mPoint[0] = mRay.GetOrigin() + intr.GetIntersection(0)*mRay.GetDirection();
			mPoint[1] = mRay.GetOrigin() + intr.GetIntersection(1)*mRay.GetDirection();
        }
        else if (mQuantity == 1)
        {
            // Point intersection.
            
			this->SetIntersectionType(IntersectionType::Point);
            mPoint[0] = mRay.GetOrigin() + intr.GetIntersection(0)*mRay.GetDirection();
        }
        else
        {
            // No intersections.
			this->SetIntersectionType(IntersectionType::Empty);
        }
    }   
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H