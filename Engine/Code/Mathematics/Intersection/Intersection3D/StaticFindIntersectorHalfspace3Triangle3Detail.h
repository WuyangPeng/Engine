// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorHalfspace3Triangle3.h"
#include "IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::StaticFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle)
	:mHalfspace{ halfspace }, mTriangle{ triangle }
{
    mQuantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
    return mHalfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
    return mTriangle;
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::Find()
{
    // Start with the triangle and then clip it against the plane.
    mQuantity = 3;
    for (auto i = 0; i < 3; ++i)
    {
        mPoint[i] = mTriangle.GetVertex()[i];
    }

    ClipConvexPolygonAgainstPlane<Real>(-mHalfspace.GetNormal(),-mHalfspace.GetConstant(), mQuantity, mPoint);
    
	if (mQuantity > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
} 

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H