// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:54)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H

#include "DistRay3Box3.h"
#include "DistLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistRay3Box3<Real>
	::DistRay3Box3 (const Ray3& ray, const Box3& box)
	:ParentType{}, mRay{ ray }, mBox{ box }
{
}

template <typename Real>
const Mathematics::Ray3<Real>& Mathematics::DistRay3Box3<Real>
	::GetRay () const
{
    return mRay;
}

template <typename Real>
const Mathematics::Box3<Real>& Mathematics::DistRay3Box3<Real>
	::GetBox () const
{
    return mBox;
}

template <typename Real>
typename const Mathematics::DistRay3Box3<Real>::DistanceResult Mathematics::DistRay3Box3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mRay.GetOrigin(), mRay.GetDirection() };
	DistLine3Box3<Real> queryLB{ line, mBox };
    auto sqrDistance = queryLB.GetSquared();
	auto lineParameter = sqrDistance.GetLhsParameter();

    if (lineParameter >= Real{})
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

	return DistanceResult{ sqrDistance.GetDistance(), Real{}, mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistRay3Box3<Real>::DistanceResult Mathematics::DistRay3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mRay.GetOrigin() + t*lhsVelocity;
	auto movedCenter = mBox.GetCenter() + t*rhsVelocity;
	Ray3 movedRay{ movedOrigin, mRay.GetDirection() };
	Box3 movedBox{ movedCenter, mBox.GetFirstAxis(),mBox.GetSecondAxis(),mBox.GetThirdAxis(),
				   mBox.GetFirstExtent(),mBox.GetSecondExtent(),mBox.GetThirdExtent() };
	return DistRay3Box3<Real>{ movedRay, movedBox }.GetSquared();
}
 
#endif // MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_DETAIL_H