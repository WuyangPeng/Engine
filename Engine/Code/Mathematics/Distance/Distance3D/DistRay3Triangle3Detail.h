// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:56)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_DETAIL_H

#include "DistRay3Triangle3.h"
#include "DistLine3Triangle3.h"
#include "DistPoint3Triangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistRay3Triangle3<Real>
	::DistRay3Triangle3 (const Ray3& ray, const Triangle3& triangle)
	:ParentType{}, mRay{ ray }, mTriangle{ triangle }
{
}

template <typename Real>
const Mathematics::Ray3<Real>& Mathematics::DistRay3Triangle3<Real>
	::GetRay () const
{
    return mRay;
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistRay3Triangle3<Real>
	::GetTriangle () const
{
    return mTriangle;
}

template <typename Real>
typename const Mathematics::DistRay3Triangle3<Real>::DistanceResult Mathematics::DistRay3Triangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mRay.GetOrigin(), mRay.GetDirection() };
	DistLine3Triangle3<Real> queryLT{ line, mTriangle };
    auto sqrDist = queryLT.GetSquared();
    mRayParameter = queryLT.GetLineParameter();

    if (mRayParameter >= Real{})
    {
        mClosestPoint0 = sqrDist.GetLhsClosestPoint();
        mClosestPoint1 = sqrDist.GetRhsClosestPoint();
        mTriangleBary[0] = queryLT.GetTriangleBary(0);
        mTriangleBary[1] = queryLT.GetTriangleBary(1);
        mTriangleBary[2] = queryLT.GetTriangleBary(2);
    }
    else
    {
        mClosestPoint0 = mRay.GetOrigin();
		DistPoint3Triangle3<Real> queryPT{ mClosestPoint0, mTriangle };
        sqrDist = queryPT.GetSquared();
        mClosestPoint1 = sqrDist.GetRhsClosestPoint();
        mRayParameter = Real{};
        mTriangleBary[0] = queryPT.GetTriangleBary(0);
        mTriangleBary[1] = queryPT.GetTriangleBary(1);
        mTriangleBary[2] = queryPT.GetTriangleBary(2);
    }
	return DistanceResult{ sqrDist.GetDistance(), Real{}, mClosestPoint0, mClosestPoint1 };    
}

template <typename Real>
typename const Mathematics::DistRay3Triangle3<Real>::DistanceResult Mathematics::DistRay3Triangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mRay.GetOrigin() + t*lhsVelocity;
	auto movedV0 = mTriangle.GetVertex(0) + t*rhsVelocity;
	auto movedV1 = mTriangle.GetVertex(1) + t*rhsVelocity;
	auto movedV2 = mTriangle.GetVertex(2) + t*rhsVelocity;
	Ray3 movedRay{ movedOrigin, mRay.GetDirection() };
	Triangle3 movedTriangle{ movedV0, movedV1, movedV2 };
	return DistRay3Triangle3<Real>{ movedRay, movedTriangle }.GetSquared();
}
 
template <typename Real>
Real Mathematics::DistRay3Triangle3<Real>
	::GetRayParameter () const
{
    return mRayParameter;
}

template <typename Real>
Real Mathematics::DistRay3Triangle3<Real>
	::GetTriangleBary (int i) const
{
    return mTriangleBary[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_DETAIL_H