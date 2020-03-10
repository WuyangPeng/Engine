// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "StaticTestIntersectorSegment3Box3.h"
#include "StaticTestIntersectorLine3Box3.h" 
#include "IntersectorUtility3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Box3<Real>
	::StaticTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid)
	: mSegment{ segment }, mBox{ box }
{  
    mSolid = solid;
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Box3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorSegment3Box3<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Box3<Real>
	::Test()
{
    Real AWdU[3], ADdU[3], AWxDdU[3], RHS;

	auto diff = mSegment.GetCenterPoint() - mBox.GetCenter();

    AWdU[0] = Math::FAbs(Vector3DTools::DotProduct(mSegment.GetDirection(),mBox.GetAxis(0)));
	ADdU[0] = Math::FAbs(Vector3DTools::DotProduct(diff,mBox.GetAxis(0)));
    RHS = mBox.GetExtent(0) + mSegment.GetExtent()*AWdU[0];
    if (ADdU[0] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	AWdU[1] = Math::FAbs(Vector3DTools::DotProduct(mSegment.GetDirection(),mBox.GetAxis(1)));
	ADdU[1] = Math::FAbs(Vector3DTools::DotProduct(diff,mBox.GetAxis(1)));
    RHS = mBox.GetExtent(1) + mSegment.GetExtent()*AWdU[1];
    if (ADdU[1] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	AWdU[2] = Math::FAbs(Vector3DTools::DotProduct(mSegment.GetDirection(),mBox.GetAxis(2)));
	ADdU[2] = Math::FAbs(Vector3DTools::DotProduct(diff,mBox.GetAxis(2)));
    RHS = mBox.GetExtent(2) + mSegment.GetExtent()*AWdU[2];
    if (ADdU[2] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	auto WxD = Vector3DTools::CrossProduct(mSegment.GetDirection(),diff);

	AWxDdU[0] = Math::FAbs(Vector3DTools::DotProduct(WxD,mBox.GetAxis(0)));
    RHS = mBox.GetExtent(1)*AWdU[2] + mBox.GetExtent(2)*AWdU[1];
    if (AWxDdU[0] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	AWxDdU[1] = Math::FAbs(Vector3DTools::DotProduct(WxD,mBox.GetAxis(1)));
    RHS = mBox.GetExtent(0)*AWdU[2] + mBox.GetExtent(2)*AWdU[0];
    if (AWxDdU[1] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	AWxDdU[2] = Math::FAbs(Vector3DTools::DotProduct(WxD,mBox.GetAxis(2)));
    RHS = mBox.GetExtent(0)*AWdU[1] + mBox.GetExtent(1)*AWdU[0];
    if (AWxDdU[2] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	this->SetIntersectionType(IntersectionType::Point);
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H