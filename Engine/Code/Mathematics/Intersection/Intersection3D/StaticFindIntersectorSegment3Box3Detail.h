// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2017
//
// “˝«Ê∞Ê±æ£∫1.0.0.0 (2017/12/21 14:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "StaticFindIntersectorSegment3Box3.h"
#include "IntersectorUtility3.h" 
#include "StaticFindIntersectorLine3Box3.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Box3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::StaticFindIntersectorSegment3Box3(const Segment3& segment,const Box3& box, bool solid)
	: mSegment{ segment }, mBox{ box }
{
    mQuantity = 0;
    mSolid = solid;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetBox() const
{
    return mBox;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::Find()
{
    auto t0 = -mSegment.GetExtent();
	auto t1 = mSegment.GetExtent();
	int mIntersectionType = 0;
	StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, mSegment.GetCenterPoint(),  mSegment.GetDirection(), mBox, mSolid, mQuantity, mPoint,  mIntersectionType);
	this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>( mIntersectionType));
}
 
template <typename Real>
int  Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const  Mathematics::Vector3D<Real>  Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H