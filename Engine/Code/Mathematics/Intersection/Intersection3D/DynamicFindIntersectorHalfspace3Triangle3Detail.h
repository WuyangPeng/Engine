// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:29)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Triangle3.h"
#include "IntersectorAxis.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::DynamicFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mHalfspace{ halfspace }, mTriangle{ triangle }
{
	mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
	return mHalfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::Find()
{
	SetContactTime(Math<Real>::sm_Zero);
	auto tlast = Math::sm_MaxReal;
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	IntersectorConfiguration<Real> cfg;
	IntersectorAxis<Real>::GetConfiguration(mHalfspace.GetNormal(), mTriangle, cfg);

	Real mContactTime = this->GetContactTime();
	if (!IntersectorAxis<Real>::Test(mHalfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, mHalfspace.GetConstant(), cfg.mMin, cfg.mMax, this->GetTMax(), mContactTime, tlast))
	{
		// Never intersecting.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	if (mContactTime == Math<Real>::sm_Zero)
	{
		// Intersecting now.
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Tri on positive side (right).
	if (cfg.mMap == IntersectorConfiguration<Real>::m12 || cfg.mMap == IntersectorConfiguration<Real>::m111)
	{
		// Point intersection.
		mQuantity = 1;
		mPoint[0] = mTriangle.GetVertex()[cfg.mIndex[0]];
	}
	else if (cfg.mMap == IntersectorConfiguration<Real>::m21)
	{
		// Segment intersection.
		mQuantity = 2;
		mPoint[0] = mTriangle.GetVertex()[cfg.mIndex[0]];
		mPoint[1] = mTriangle.GetVertex()[cfg.mIndex[1]];
	}
	else
	{
		// Face intersection.
		mQuantity = 3;
		for (auto i = 0; i < 3; ++i)
		{
			mPoint[i] = mTriangle.GetVertex()[i];
		}
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
int Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H