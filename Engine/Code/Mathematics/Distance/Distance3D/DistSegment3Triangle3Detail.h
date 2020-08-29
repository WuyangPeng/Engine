// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:54)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DistSegment3Triangle3.h"
#include "DistLine3Triangle3.h"
#include "DistPoint3Triangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistSegment3Triangle3<Real>
	::DistSegment3Triangle3(const Segment3& rkSegment, const Triangle3& rkTriangle)
	:ParentType{}, mSegment{ rkSegment }, mTriangle{ rkTriangle }
{
}

template <typename Real>
const Mathematics::Segment3<Real>& Mathematics::DistSegment3Triangle3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistSegment3Triangle3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
typename const Mathematics::DistSegment3Triangle3<Real>::DistanceResult Mathematics::DistSegment3Triangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mSegment.GetCenterPoint(), mSegment.GetDirection() };
	DistLine3Triangle3<Real> queryLT{ line, mTriangle };
	auto sqrDist = queryLT.GetSquared();
	mSegmentParameter = queryLT.GetLineParameter();

	if (mSegmentParameter >= -mSegment.GetExtent())
	{
		if (mSegmentParameter <= mSegment.GetExtent())
		{
			mClosestPoint0 = sqrDist.GetLhsClosestPoint();
			mClosestPoint1 = sqrDist.GetRhsClosestPoint();
			mTriangleBary[0] = queryLT.GetTriangleBary(0);
			mTriangleBary[1] = queryLT.GetTriangleBary(1);
			mTriangleBary[2] = queryLT.GetTriangleBary(2);
		}
		else
		{
			mClosestPoint0 = mSegment.GetEndPoint();
			DistPoint3Triangle3<Real> queryPT{ mClosestPoint0, mTriangle };
			sqrDist = queryPT.GetSquared();
			mClosestPoint1 = sqrDist.GetRhsClosestPoint();
			mSegmentParameter = mSegment.GetExtent();
			mTriangleBary[0] = queryPT.GetTriangleBary(0);
			mTriangleBary[1] = queryPT.GetTriangleBary(1);
			mTriangleBary[2] = queryPT.GetTriangleBary(2);
		}
	}
	else
	{
		mClosestPoint0 = mSegment.GetBeginPoint();
		DistPoint3Triangle3<Real> queryPT{ mClosestPoint0, mTriangle };
		sqrDist = queryPT.GetSquared();
		mClosestPoint1 = sqrDist.GetRhsClosestPoint();
		mSegmentParameter = -mSegment.GetExtent();
		mTriangleBary[0] = queryPT.GetTriangleBary(0);
		mTriangleBary[1] = queryPT.GetTriangleBary(1);
		mTriangleBary[2] = queryPT.GetTriangleBary(2);
	}

	return DistanceResult{ sqrDist.GetDistance(), Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistSegment3Triangle3<Real>::DistanceResult Mathematics::DistSegment3Triangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedCenter = mSegment.GetCenterPoint() + t * lhsVelocity;
	auto movedV0 = mTriangle.GetVertex(0) + t * rhsVelocity;
	auto movedV1 = mTriangle.GetVertex(1) + t * rhsVelocity;
	auto movedV2 = mTriangle.GetVertex(2) + t * rhsVelocity;
	Segment3 movedSeg{ movedCenter, mSegment.GetDirection(), mSegment.GetExtent() };
	Triangle3 movedTriangle{ movedV0, movedV1, movedV2 };
	return DistSegment3Triangle3<Real>{ movedSeg, movedTriangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistSegment3Triangle3<Real>
	::GetSegmentParameter() const
{
	return mSegmentParameter;
}

template <typename Real>
Real Mathematics::DistSegment3Triangle3<Real>
	::GetTriangleBary(int i) const
{
	return mTriangleBary[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_DETAIL_H