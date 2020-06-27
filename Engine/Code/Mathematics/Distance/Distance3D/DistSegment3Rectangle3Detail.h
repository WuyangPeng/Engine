// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:53)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_DETAIL_H

#include "DistSegment3Rectangle3.h"
#include "DistLine3Rectangle3.h"
#include "DistPoint3Rectangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistSegment3Rectangle3<Real>
	::DistSegment3Rectangle3(const Segment3& segment, const Rectangle3& rectangle)
	:ParentType{}, mSegment{ segment }, mRectangle{ rectangle }
{
}

template <typename Real>
const Mathematics::Segment3<Real>& Mathematics::DistSegment3Rectangle3<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistSegment3Rectangle3<Real>
	::GetRectangle() const
{
	return mRectangle;
}

template <typename Real>
typename const Mathematics::DistSegment3Rectangle3<Real>::DistanceResult Mathematics::DistSegment3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mSegment.GetCenterPoint(), mSegment.GetDirection() };
	DistLine3Rectangle3<Real> queryLR{ line, mRectangle };
	auto sqrDist = queryLR.GetSquared();
	mSegmentParameter = queryLR.GetLineParameter();

	if (mSegmentParameter >= -mSegment.GetExtent())
	{
		if (mSegmentParameter <= mSegment.GetExtent())
		{
			mClosestPoint0 = sqrDist.GetLhsClosestPoint();
			mClosestPoint1 = sqrDist.GetRhsClosestPoint();
			mRectCoord[0] = queryLR.GetRectangleCoordinate(0);
			mRectCoord[1] = queryLR.GetRectangleCoordinate(1);
		}
		else
		{
			mClosestPoint0 = mSegment.GetEndPoint();
			DistPoint3Rectangle3<Real> queryPR{ mClosestPoint0,mRectangle };
			sqrDist = queryPR.GetSquared();
			mClosestPoint1 = sqrDist.GetRhsClosestPoint();
			mSegmentParameter = mSegment.GetExtent();
			mRectCoord[0] = queryPR.GetRectangleCoordinate(0);
			mRectCoord[1] = queryPR.GetRectangleCoordinate(1);
		}
	}
	else
	{
		mClosestPoint0 = mSegment.GetBeginPoint();
		DistPoint3Rectangle3<Real> queryPR{ mClosestPoint0, mRectangle };
		sqrDist = queryPR.GetSquared();
		mClosestPoint1 = sqrDist.GetRhsClosestPoint();
		mSegmentParameter = -mSegment.GetExtent();
		mRectCoord[0] = queryPR.GetRectangleCoordinate(0);
		mRectCoord[1] = queryPR.GetRectangleCoordinate(1);
	}
	return DistanceResult{ sqrDist.GetDistance(), Math<Real>::sm_Zero, mClosestPoint0, mClosestPoint1 };
}


template <typename Real>
typename const Mathematics::DistSegment3Rectangle3<Real>::DistanceResult Mathematics::DistSegment3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedCenter0 = mSegment.GetCenterPoint() + t * lhsVelocity;
	auto movedCenter1 = mRectangle.GetCenter() + t * rhsVelocity;
	Segment3 movedSeg{ movedCenter0, mSegment.GetDirection(),mSegment.GetExtent() };
	Rectangle3 movedRect{ movedCenter1, mRectangle.GetFirstAxis(),mRectangle.GetSecondAxis(),mRectangle.GetFirstExtent(),mRectangle.GetSecondExtent() };
	return DistSegment3Rectangle3<Real>{ movedSeg, movedRect }.GetSquared();
}

template <typename Real>
Real Mathematics::DistSegment3Rectangle3<Real>
	::GetSegmentParameter() const
{
	return mSegmentParameter;
}

template <typename Real>
Real Mathematics::DistSegment3Rectangle3<Real>
	::GetRectangleCoordinate(int i) const
{
	return mRectCoord[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_DETAIL_H