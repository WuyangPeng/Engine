// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:49)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_DETAIL_H

#include "DistPoint3Plane3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"  

template <typename Real>
Mathematics::DistPoint3Plane3<Real>
	::DistPoint3Plane3(const Vector3D& point, const Plane3& plane)
	:ParentType{}, mPoint{ point }, mPlane{ plane }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Plane3<Real>
	::GetPoint() const
{
	return mPoint;
}

template <typename Real>
const Mathematics::Plane3<Real>& Mathematics::DistPoint3Plane3<Real>
	::GetPlane() const
{
	return mPlane;
}

template <typename Real>
typename const Mathematics::DistPoint3Plane3<Real>::DistanceResult Mathematics::DistPoint3Plane3<Real>
	::GetSquared() const
{
	auto signedDistance = Vector3DTools::DotProduct(mPlane.GetNormal(), mPoint) - mPlane.GetConstant();

	return DistanceResult{ Math::FAbs(signedDistance), Math<Real>::sm_Zero, mPoint, mPoint - signedDistance * mPlane.GetNormal() };
}

template <typename Real>
typename const Mathematics::DistPoint3Plane3<Real>::DistanceResult Mathematics::DistPoint3Plane3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t * lhsVelocity;
	auto movedConstant = mPlane.GetConstant() + t * Vector3DTools::DotProduct(mPlane.GetNormal(), rhsVelocity);
	Plane3 movedPlane{ mPlane.GetNormal(), movedConstant };
	return DistPoint3Plane3<Real>{ movedPoint, movedPlane }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_DETAIL_H