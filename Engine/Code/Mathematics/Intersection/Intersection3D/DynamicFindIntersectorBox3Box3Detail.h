// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:23)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicFindIntersectorBox3Box3.h"
#include "IntersectorConfiguration.h"
#include "FindContactSet.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::DynamicFindIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mBox0{ box0 }, mBox1{ box1 }
{
	mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::GetBox0() const
{
	return mBox0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::GetBox1() const
{
	return mBox1;
} 

template <typename Real>
void Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::Find()
{
	mQuantity = 0;

	SetContactTime(Math::sm_Zero);
	auto tlast = Math::sm_MaxReal;
	auto mContactTime = Math::sm_Zero;

	// Relative velocity of box1 relative to box0.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	auto i0 = 0;
	auto i1 = 0;
	auto side = IntersectorConfiguration<Real>::NONE;
	IntersectorConfiguration<Real> box0Cfg, box1Cfg;
	Vector3D axis;

	// box 0 normals
	for (i0 = 0; i0 < 3; ++i0)
	{
		axis = mBox0.GetAxis(i0);

		if (!IntersectorAxis<Real>::Find(axis, mBox0, mBox1, relVelocity, this->GetTMax(), mContactTime, tlast, side, box0Cfg, box1Cfg))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			SetContactTime(mContactTime);
			return;
		}

		SetContactTime(mContactTime);
	}

	// box 1 normals
	for (i1 = 0; i1 < 3; ++i1)
	{
		axis = mBox1.GetAxis(i1);

		if (!IntersectorAxis<Real>::Find(axis, mBox0, mBox1, relVelocity, this->GetTMax(), mContactTime, tlast, side, box0Cfg, box1Cfg))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			SetContactTime(mContactTime);
			return;
		}

		SetContactTime(mContactTime);
	}

	// box 0 edges cross box 1 edges
	for (i0 = 0; i0 < 3; ++i0)
	{
		for (i1 = 0; i1 < 3; ++i1)
		{
			axis = Vector3DTools::CrossProduct(mBox0.GetAxis(i0), mBox1.GetAxis(i1));

			// Since all axes are unit length (assumed), then can just compare
			// against a constant (not relative) epsilon.
			if (Vector3DTools::VectorMagnitudeSquared(axis) <= Math::sm_ZeroTolerance)
			{
				// Axis i0 and i1 are parallel.  If any two axes are parallel,
				// then the only comparisons that needed are between the faces
				// themselves.  At this time the faces have already been
				// tested, and without separation, so all further separation
				// tests will show only overlaps.

				FindContactSet<Real>(mBox0, mBox1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), mContactTime, mQuantity, mPoint);
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Other);
				return;
			}

			if (!IntersectorAxis<Real>::Find(axis, mBox0, mBox1, relVelocity, this->GetTMax(), mContactTime, tlast, side, box0Cfg, box1Cfg))
			{
				this->SetIntersectionType(IntersectionType::Empty);
				SetContactTime(mContactTime);
				return;
			}

			SetContactTime(mContactTime);
		}
	}

	// velocity cross box 0 edges
	for (i0 = 0; i0 < 3; ++i0)
	{
		axis = Vector3DTools::CrossProduct(relVelocity, mBox0.GetAxis(i0));
		if (!IntersectorAxis<Real>::Find(axis, mBox0, mBox1, relVelocity, this->GetTMax(), mContactTime, tlast, side, box0Cfg, box1Cfg))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			SetContactTime(mContactTime);
			return;
		}

		SetContactTime(mContactTime);
	}

	// velocity cross box 1 edges
	for (i1 = 0; i1 < 3; ++i1)
	{
		axis = Vector3DTools::CrossProduct(relVelocity, mBox1.GetAxis(i1));
		if (!IntersectorAxis<Real>::Find(axis, mBox0, mBox1, relVelocity, this->GetTMax(), mContactTime, tlast, side, box0Cfg, box1Cfg))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			SetContactTime(mContactTime);
			return;
		}

		SetContactTime(mContactTime);
	}

	if (mContactTime <= Math::sm_Zero || side == IntersectorConfiguration<Real>::NONE)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		SetContactTime(mContactTime);
		return;
	}

	FindContactSet<Real>(mBox0, mBox1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), mContactTime, mQuantity, mPoint);

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Other);

	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H