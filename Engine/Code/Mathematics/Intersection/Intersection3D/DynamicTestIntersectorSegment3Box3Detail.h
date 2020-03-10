// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 13:35)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicTestIntersectorSegment3Box3.h"
 
template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::DynamicTestIntersectorSegment3Box3 (const Segment3& segment, const Box3& box,bool solid,Real tmax, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSegment{ segment }, mBox{ box }
{     
    mSolid = solid;
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::GetSegment () const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::GetBox () const
{
    return mBox;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Box3<Real>
	::Test ()
{
	// Get the endpoints of the segment.
    Vector3D segment[2] {  mSegment.GetBeginPoint(), mSegment.GetEndPoint() };

    // Get the box velocity relative to the segment.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    Real mContactTime = Real{};
    Real tlast = Math::sm_MaxReal;

    int i;
    Vector3D axis;

    // Test box normals.
    for (i = 0; i < 3; ++i)
    {
        axis = mBox.GetAxis(i);
        if (!IntersectorAxis<Real>::Test(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast))
        {
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // Test seg-direction cross box-edges.
    for (i = 0; i < 3; ++i)
    {
        axis = Vector3DTools::CrossProduct(mBox.GetAxis(i),mSegment.GetDirection());
        if (!IntersectorAxis<Real>::Test(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast))
        {
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // Test velocity cross box-faces.
    for (i = 0; i < 3; i++)
    {
        axis = Vector3DTools::CrossProduct(relVelocity,mBox.GetAxis(i));
        if (!IntersectorAxis<Real>::Test(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast))
        {
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Point);
	return;
}
 
#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H