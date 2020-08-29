// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::StaticFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere)
	: mSegment{ segment }, mSphere{ sphere }
{
    mQuantity = 0;
    ZeroThreshold = Math::GetZeroTolerance();
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::Find()
{
	auto diff = mSegment.GetCenterPoint() - mSphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - mSphere.GetRadius()*mSphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(mSegment.GetDirection(),diff);
	auto discr = a1*a1 - a0;
    if (discr < Math<Real>::GetZero())
    {
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto tmp0 = mSegment.GetExtent()*mSegment.GetExtent() + a0;
	auto tmp1 = (static_cast<Real>(2))*a1*mSegment.GetExtent();
	auto qm = tmp0 - tmp1;
	auto qp = tmp0 + tmp1;
    Real root;
    if (qm*qp <= Math<Real>::GetZero())
    {
        root = Math::Sqrt(discr);
        mSegmentParameter[0] = (qm > Math<Real>::GetZero() ? -a1 - root : -a1 + root);
        mPoint[0] = mSegment.GetCenterPoint() + mSegmentParameter[0] * mSegment.GetDirection();
        mQuantity = 1;
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (qm > Math<Real>::GetZero() && Math::FAbs(a1) < mSegment.GetExtent())
    {
        if (discr >= ZeroThreshold)
        {
            root = Math::Sqrt(discr);
            mSegmentParameter[0] = -a1 - root;
            mSegmentParameter[1] = -a1 + root;
            mPoint[0] = mSegment.GetCenterPoint() + mSegmentParameter[0] *  mSegment.GetDirection();
            mPoint[1] = mSegment.GetCenterPoint() + mSegmentParameter[1] * mSegment.GetDirection();
            mQuantity = 2;
			this->SetIntersectionType(IntersectionType::Segment);
        }
        else
        {
            mSegmentParameter[0] = -a1;
            mPoint[0] = mSegment.GetCenterPoint() + mSegmentParameter[0] * mSegment.GetDirection();
            mQuantity = 1;
			this->SetIntersectionType(IntersectionType::Point);
        }
    }
    else
    {
        mQuantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
    }   
}
 
template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSegmentParameter(int i) const
{
    return mSegmentParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H