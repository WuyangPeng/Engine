// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:28)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Segment3.h"
#include "IntersectorAxis.h"
#include "IntersectorConfiguration.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::DynamicFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mSegment{ segment }
{
	mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::Find()
{
	SetContactTime(Math<Real>::GetZero());
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	Vector3D segment[2]{ mSegment.GetBeginPoint(), mSegment.GetEndPoint() };

	IntersectorConfiguration<Real> cfg;
	IntersectorAxis<Real>::GetConfiguration(mHalfspace.GetNormal(), segment, cfg);

	auto mContactTime = this->GetContactTime();
	if (!IntersectorAxis<Real>::Test(mHalfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, mHalfspace.GetConstant(), cfg.mMin, cfg.mMax, this->GetTMax(), mContactTime, tlast))
	{
		// Never intersecting.
		this->SetIntersectionType(IntersectionType::Empty);
		SetContactTime(mContactTime);
		return;
	}

	if (mContactTime == Math<Real>::GetZero())
	{
		// Intersecting now.
		this->SetIntersectionType(IntersectionType::Empty);
		SetContactTime(mContactTime);
		return;
	}

	// Line on positive side (right).
	if (cfg.mMap == IntersectorConfiguration<Real>::m11)
	{
		mQuantity = 1;
		mPoint[0] = segment[cfg.mIndex[0]];
	}
	else // cfg.mMap == IntersectorConfiguration<Real>::m2
	{
		mQuantity = 2;
		mPoint[0] = segment[cfg.mIndex[0]];
		mPoint[1] = segment[cfg.mIndex[1]];
	}

	// Adjust points to the correct place in time, as well.
	auto diff = mContactTime * this->GetRhsVelocity();
	for (auto i = 0; i < mQuantity; ++i)
	{
		mPoint[i] += diff;
	}
	this->SetIntersectionType(IntersectionType::Other);
	SetContactTime(mContactTime);
	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H