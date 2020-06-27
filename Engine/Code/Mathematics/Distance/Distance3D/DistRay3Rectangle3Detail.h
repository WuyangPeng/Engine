// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:51)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_DETAIL_H

#include "DistRay3Rectangle3.h"
#include "DistLine3Rectangle3.h"
#include "DistPoint3Rectangle3.h" 
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistRay3Rectangle3<Real>
	::DistRay3Rectangle3(const Ray3& ray, const Rectangle3& rectangle)
	:ParentType{}, mRay{ ray }, mRectangle{ rectangle }
{
}

template <typename Real>
const Mathematics::Ray3<Real>& Mathematics::DistRay3Rectangle3<Real>
	::GetRay() const
{
	return mRay;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistRay3Rectangle3<Real>
	::GetRectangle() const
{
	return mRectangle;
}

template <typename Real>
typename const Mathematics::DistRay3Rectangle3<Real>::DistanceResult Mathematics::DistRay3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mRay.GetOrigin(), mRay.GetDirection() };
	DistLine3Rectangle3<Real> queryLR{ line, mRectangle };
	auto sqrDist = queryLR.GetSquared();
	mRayParameter = sqrDist.GetLhsParameter();

	if (mRayParameter >= Math<Real>::sm_Zero)
	{
		mClosestPoint0 = sqrDist.GetLhsClosestPoint();
		mClosestPoint1 = sqrDist.GetRhsClosestPoint();
		mRectCoord[0] = queryLR.GetRectangleCoordinate(0);
		mRectCoord[1] = queryLR.GetRectangleCoordinate(1);
	}
	else
	{
		mClosestPoint0 = mRay.GetOrigin();
		DistPoint3Rectangle3<Real> queryPR{ mClosestPoint0, mRectangle };
		sqrDist = queryPR.GetSquared();
		mClosestPoint1 = sqrDist.GetRhsClosestPoint();
		mRayParameter = Math<Real>::sm_Zero;
		mRectCoord[0] = queryPR.GetRectangleCoordinate(0);
		mRectCoord[1] = queryPR.GetRectangleCoordinate(1);
	}

	return DistanceResult{ sqrDist.GetDistance(), Math<Real>::sm_Zero, mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistRay3Rectangle3<Real>::DistanceResult Mathematics::DistRay3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mRay.GetOrigin() + t * lhsVelocity;
	auto movedCenter = mRectangle.GetCenter() + t * rhsVelocity;
	Ray3 movedRay{ movedOrigin, mRay.GetDirection() };
	Rectangle3 movedRectangle{ movedCenter, mRectangle.GetFirstAxis(),mRectangle.GetSecondAxis(),
							   mRectangle.GetExtent(0),mRectangle.GetExtent(1) };
	return DistRay3Rectangle3<Real>{ movedRay, movedRectangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistRay3Rectangle3<Real>
	::GetRayParameter() const
{
	return mRayParameter;
}

template <typename Real>
Real Mathematics::DistRay3Rectangle3<Real>
	::GetRectangleCoordinate(int i) const
{
	return mRectCoord[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_DETAIL_H