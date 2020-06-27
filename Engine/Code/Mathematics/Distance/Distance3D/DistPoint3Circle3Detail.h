// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:47)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_DETAIL_H 

#include "DistPoint3Circle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistPoint3Circle3<Real>
	::DistPoint3Circle3(const Vector3D& point, const Circle3& circle)
	:ParentType{}, mPoint{ point }, mCircle{ circle }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Circle3<Real>
	::GetPoint() const
{
	return mPoint;
}

template <typename Real>
const Mathematics::Circle3<Real>& Mathematics::DistPoint3Circle3<Real>
	::GetCircle() const
{
	return mCircle;
}

template <typename Real>
typename const Mathematics::DistPoint3Circle3<Real>::DistanceResult Mathematics::DistPoint3Circle3<Real>
	::GetSquared() const
{
	// Projection of P-C onto plane is Q-C = P-C - Dot(N,P-C)*N.
	auto PmC = mPoint - mCircle.GetCenter();
	auto QmC = PmC - Vector3DTools::DotProduct(mCircle.GetNormal(), PmC)*mCircle.GetNormal();
	auto lengthQmC = Vector3DTools::VectorMagnitude(QmC);
	Vector3D mClosestPoint1;
	auto mHasMultipleClosestPoints1 = false;
	if (lengthQmC > Math<Real>::sm_Zero)
	{
		mClosestPoint1 = mCircle.GetCenter() + mCircle.GetRadius() * QmC / lengthQmC;
		mHasMultipleClosestPoints1 = false;
	}
	else
	{
		// All circle points are equidistant from P.  Return one of them.
		mClosestPoint1 = mCircle.GetCenter() + mCircle.GetRadius() * mCircle.GetDirection0();
		mHasMultipleClosestPoints1 = true;
	}

	auto mClosestPoint0 = mPoint;

	auto diff = mClosestPoint0 - mClosestPoint1;
	auto sqrDistance = Vector3DTools::DotProduct(diff, diff);

	return DistanceResult{ sqrDistance,Math<Real>::sm_Zero,mClosestPoint0,mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistPoint3Circle3<Real>::DistanceResult Mathematics::DistPoint3Circle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t * lhsVelocity;
	auto movedCenter = mCircle.GetCenter() + t * rhsVelocity;
	Circle3 movedCircle{ movedCenter, mCircle.GetDirection0(), mCircle.GetDirection1(), mCircle.GetNormal(),mCircle.GetRadius() };
	return DistPoint3Circle3<Real>{ movedPoint, movedCircle }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_DETAIL_H