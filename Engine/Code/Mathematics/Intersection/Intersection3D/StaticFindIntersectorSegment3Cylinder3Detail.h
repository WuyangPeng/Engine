// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorSegment3Cylinder3.h"
#include "StaticFindIntersectorLine3Cylinder3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::StaticFindIntersectorSegment3Cylinder3 (const Segment3& segment, const Cylinder3& cylinder)
	:mSegment{ segment }, mCylinder{ cylinder }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetCylinder() const
{
    return mCylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::Find()
{
    Real t[2];
	auto quantity = StaticFindIntersectorLine3Cylinder3<Real>::Find(mSegment.GetCenterPoint(), mSegment.GetDirection(), mCylinder, t);

    mQuantity = 0;
    for (auto i = 0; i < quantity; ++i)
    {
        if (Math::FAbs(t[i]) <= mSegment.GetExtent())
        {
			mPoint[mQuantity++] = mSegment.GetCenterPoint() +  t[i]*mSegment.GetDirection();
        }
    }

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

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}
 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H