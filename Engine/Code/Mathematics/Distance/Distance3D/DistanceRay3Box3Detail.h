// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:51)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H

#include "DistanceRay3Box3.h"
#include "DistanceLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistanceRay3Box3<Real>
	::DistanceRay3Box3(const Ray3& ray, const Box3& box)
	:ParentType{}, mRay{ ray }, mBox{ box }
{
}

template <typename Real>
const Mathematics::Ray3<Real>& Mathematics::DistanceRay3Box3<Real>
	::GetRay() const
{
	return mRay;
}

template <typename Real>
const Mathematics::Box3<Real>& Mathematics::DistanceRay3Box3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
typename const Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mRay.GetOrigin(), mRay.GetDirection() };
	DistanceLine3Box3<Real> queryLB{ line, mBox };
	auto sqrDistance = queryLB.GetSquared();
	auto lineParameter = sqrDistance.GetLhsParameter();

	if (lineParameter >= Math<Real>::GetValue(0))
	{
		mClosestPoint0 = sqrDistance.GetLhsClosestPoint();
		mClosestPoint1 = sqrDistance.GetRhsClosestPoint();
	}
	else
	{
		DistancePoint3Box3<Real> queryPB{ mRay.GetOrigin(), mBox };
		sqrDistance = queryPB.GetSquared();
		mClosestPoint0 = sqrDistance.GetLhsClosestPoint();
		mClosestPoint1 = sqrDistance.GetRhsClosestPoint();
	}

	return DistanceResult{ sqrDistance.GetDistance(), Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mRay.GetOrigin() + t * lhsVelocity;
	auto movedCenter = mBox.GetCenter() + t * rhsVelocity;
	Ray3 movedRay{ movedOrigin, mRay.GetDirection() };
	Box3 movedBox{ movedCenter, mBox.GetAxis0(),mBox.GetAxis1(),mBox.GetAxis2(),
				   mBox.GetExtent0(),mBox.GetExtent1(),mBox.GetExtent2() };
	return DistanceRay3Box3<Real>{ movedRay, movedBox }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H