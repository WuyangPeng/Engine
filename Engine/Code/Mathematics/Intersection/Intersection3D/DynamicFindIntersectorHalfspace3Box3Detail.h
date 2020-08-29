// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:28)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Box3.h" 

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::DynamicFindIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mBox{ box }
{
	mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::Find()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	IntersectorConfiguration<Real> cfg;
	IntersectorAxis<Real>::GetConfiguration(mHalfspace.GetNormal(), mBox, cfg);

	Real mContactTime = Math<Real>::GetZero();
	if (!IntersectorAxis<Real>::Test(mHalfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, mHalfspace.GetConstant(), cfg.mMin, cfg.mMax, this->GetTMax(), mContactTime, tlast))
	{
		// Never intersecting.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	if (mContactTime == Math<Real>::GetZero())
	{
		// Intersecting now.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Box on positive side (right).
	if (cfg.mMap == IntersectorConfiguration<Real>::m1_1)
	{
		// Point intersection.
		mQuantity = 1;
		mPoint[0] = GetPointFromIndex(cfg.mIndex[0], mBox);
	}
	else if (cfg.mMap == IntersectorConfiguration<Real>::m2_2)
	{
		// Segment intersection.
		mQuantity = 2;
		mPoint[0] = GetPointFromIndex(cfg.mIndex[0], mBox);
		mPoint[1] = GetPointFromIndex(cfg.mIndex[1], mBox);
	}
	else // cfg.mMap == IntersectorConfiguration<Real>::m44
	{
		// Face intersection.
		mQuantity = 4;
		mPoint[0] = GetPointFromIndex(cfg.mIndex[0], mBox);
		mPoint[1] = GetPointFromIndex(cfg.mIndex[1], mBox);
		mPoint[2] = GetPointFromIndex(cfg.mIndex[2], mBox);
		mPoint[3] = GetPointFromIndex(cfg.mIndex[3], mBox);
	}

	// Adjust points to the correct place in time, as well.
	auto diff = mContactTime * this->GetRhsVelocity();
	for (auto i = 0; i < mQuantity; ++i)
	{
		mPoint[i] += diff;
	}
	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Other);
	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H