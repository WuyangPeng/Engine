// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:48)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorSegment3Triangle3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>
	::DynamicTestIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSegment{ segment }, mTriangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>
	::Test()
{
	// Get the endpoints of the segment.
	Vector3D segment[2]{ mSegment.GetBeginPoint(), mSegment.GetEndPoint() };

	// Get the triangle edges.
	auto edge0 = mTriangle.GetVertex()[1] - mTriangle.GetVertex()[0];
	auto edge1 = mTriangle.GetVertex()[2] - mTriangle.GetVertex()[0];

	// Get the triangle velocity relative to the segment.
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

	auto  mContactTime = Math<Real>::GetZero();
	auto tlast = Math::sm_MaxReal;

	// Test tri-normal.
	auto normV = Vector3DTools::CrossProduct(edge0, edge1);
	if (!IntersectorAxis<Real>::Test(normV, segment, mTriangle, relVelocity, this->GetTMax(), mContactTime, tlast))
	{
		SetContactTime(mContactTime);
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Test whether the segment is parallel to the triangle, effectively the
	// test:  sin(Angle(NormV,DirU)) > 1-epsilon
	auto dirU = segment[1] - segment[0];
	auto normU = Vector3DTools::CrossProduct(normV, dirU);
	auto dirSqrLen = Vector3DTools::VectorMagnitudeSquared(dirU);
	auto norUSqrLen = Vector3DTools::VectorMagnitudeSquared(normU);
	auto norVSqrLen = Vector3DTools::VectorMagnitudeSquared(normV);
	auto oneMinusEpsilon = static_cast<Real>(1) - Math::GetZeroTolerance();

	auto i0 = 0;
	auto i1 = 0;
	Vector3D axis;

	if (norUSqrLen > oneMinusEpsilon*norVSqrLen*dirSqrLen)  // parallel
	{
		// Test tri-normal cross seg-direction.
		if (!IntersectorAxis<Real>::Test(normU, segment, mTriangle, relVelocity, this->GetTMax(), mContactTime, tlast))
		{
			SetContactTime(mContactTime);
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}

		// Test tri-normal cross tri-edges.
		for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
		{
			axis = Vector3DTools::CrossProduct(normV, (mTriangle.GetVertex()[i1] - mTriangle.GetVertex()[i0]));

			if (!IntersectorAxis<Real>::Test(axis, segment, mTriangle, relVelocity, this->GetTMax(), mContactTime, tlast))
			{
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}
	else  // not parallel
	{
		// Test seg-direction cross tri-edges.
		for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
		{
			axis = Vector3DTools::CrossProduct(dirU, (mTriangle.GetVertex()[i1] - mTriangle.GetVertex()[i0]));

			if (!IntersectorAxis<Real>::Test(axis, segment, mTriangle, relVelocity, this->GetTMax(), mContactTime, tlast))
			{
				SetContactTime(mContactTime);
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
	}

	SetContactTime(mContactTime);
	this->SetIntersectionType(IntersectionType::Point);
	return;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H