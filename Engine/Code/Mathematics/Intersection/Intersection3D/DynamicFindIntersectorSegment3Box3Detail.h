// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 13:03)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicFindIntersectorSegment3Box3.h"
#include "StaticFindIntersectorLine3Box3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::DynamicFindIntersectorSegment3Box3 (const Segment3& segment, const Box3& box,bool solid,Real tmax, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSegment{ segment }, mBox{ box }
{
    mQuantity = 0;
    mSolid = solid;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetSegment () const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetBox () const
{
    return mBox;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::Find ()
{
    mQuantity = 0;
	this->SetIntersectionType(IntersectionType::Empty);

    // Get the endpoints of the segment.
    Vector3D segment[2] { mSegment.GetBeginPoint(), mSegment.GetEndPoint() };

    // Get the box velocity relative to the segment.
	auto relVelocity = this-> GetRhsVelocity() - this->GetLhsVelocity();

    SetContactTime(Real{});
    Real tlast = Math::sm_MaxReal;

    int i;
    Vector3D axis;
	auto side = IntersectorConfiguration<Real>::NONE;
    IntersectorConfiguration<Real> segContact, boxContact;
	auto mContactTime= this->GetContactTime();
    // Test box normals.
    for (i = 0; i < 3; ++i)
    {
        axis = mBox.GetAxis(i);
        if (!IntersectorAxis<Real>::Find(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast, side, segContact, boxContact))
        {
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // Test seg-direction cross box-edges.
    for (i = 0; i < 3; i++)
    {
        axis = Vector3DTools::CrossProduct(mBox.GetAxis(i),mSegment.GetDirection());
        if (!IntersectorAxis<Real>::Find(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast, side, segContact, boxContact))
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
        if (!IntersectorAxis<Real>::Find(axis, segment, mBox, relVelocity, this->GetTMax(),mContactTime, tlast, side, segContact, boxContact))
        {
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    if (mContactTime < Real{} || side == IntersectorConfiguration<Real>::NONE)
    {
        // intersecting now
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    FindContactSet<Real>(segment, mBox, side, segContact, boxContact,this->GetLhsVelocity(), this->GetRhsVelocity(), mContactTime, mQuantity, mPoint);

	SetContactTime(mContactTime);
    if (mQuantity == 1)
    {
		this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
		this->SetIntersectionType(IntersectionType::Segment);
    }

    return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetQuantity () const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>
	::GetPoint (int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H