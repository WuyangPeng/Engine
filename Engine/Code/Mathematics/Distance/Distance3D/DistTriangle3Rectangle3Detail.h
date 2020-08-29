// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:54)

#ifndef MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_DETAIL_H

#include "DistTriangle3Rectangle3.h"
#include "DistSegment3Triangle3.h"
#include "DistSegment3Rectangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistTriangle3Rectangle3<Real>
	::DistTriangle3Rectangle3(const Triangle3& rkTriangle, const Rectangle3& rkRectangle)
	:ParentType{}, mTriangle{ rkTriangle }, mRectangle{ rkRectangle }
{
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistTriangle3Rectangle3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistTriangle3Rectangle3<Real>
	::GetRectangle() const
{
	return mRectangle;
}

template <typename Real>
typename const Mathematics::DistTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistTriangle3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	// Compare edges of triangle to the interior of rectangle.
	auto sqrDist = Math::sm_MaxReal;

	auto i0 = 0;
	auto i1 = 0;
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		auto center = (static_cast<Real>(0.5))*(mTriangle.GetVertex(i0) + mTriangle.GetVertex(i1));
		auto direction = mTriangle.GetVertex(i1) - mTriangle.GetVertex(i0);
		auto extent = (static_cast<Real>(0.5))*Vector3DTools::VectorMagnitude(direction);

		Segment3<Real> edge{ extent,center,direction };

		DistSegment3Rectangle3<Real> querySR{ edge, mRectangle };
		auto sqrDistTmp = querySR.GetSquared();
		if (sqrDistTmp.GetDistance() < sqrDist)
		{
			// The triangle point is reported in mClosestPoint0 and the
			// rectangle point is reported in mClosestPoint1.  The querySR
			// calculator is for triangleEdge-rectangle, so GetClosestPoint0()
			// and GetClosestPoint1() must be called as listed next.
			mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
			mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
			sqrDist = sqrDistTmp.GetDistance();
		}
	}

	// Compare edges of rectangle to the interior of triangle.
	for (i1 = 0; i1 < 2; ++i1)
	{
		for (i0 = -1; i0 <= 1; i0 += 2)
		{
			auto center = mRectangle.GetCenter() + (i0*mRectangle.GetExtent(1 - i1)) * mRectangle.GetAxis(1 - i1);
			auto direction = mRectangle.GetAxis(i1);
			auto extent = mRectangle.GetExtent(i1);

			Segment3<Real> edge{ extent,center,direction };

			DistSegment3Triangle3<Real> queryST{ edge, mTriangle };
			auto sqrDistTmp = queryST.GetSquared();
			if (sqrDistTmp.GetDistance() < sqrDist)
			{
				// The triangle point is reported in mClosestPoint0 and the
				// rectangle point is reported in mClosestPoint1.  The queryST
				// calculator is for rectangleEdge-triangle, so
				// GetClosestPoint1() and GetClosestPoint0() must be called as
				// listed next.
				mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
				mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
				sqrDist = sqrDistTmp.GetDistance();
			}
		}
	}
	return DistanceResult{ sqrDist, Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistTriangle3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedV0 = mTriangle.GetVertex(0) + t * lhsVelocity;
	auto movedV1 = mTriangle.GetVertex(1) + t * lhsVelocity;
	auto movedV2 = mTriangle.GetVertex(2) + t * lhsVelocity;
	auto movedCenter = mRectangle.GetCenter() + t * rhsVelocity;
	Triangle3 movedTri{ movedV0, movedV1, movedV2 };
	Rectangle3 movedRect{ movedCenter, mRectangle.GetFirstAxis(),mRectangle.GetSecondAxis(),mRectangle.GetFirstExtent(),mRectangle.GetSecondExtent() };
	return DistTriangle3Rectangle3<Real>{ movedTri, movedRect }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_DETAIL_H