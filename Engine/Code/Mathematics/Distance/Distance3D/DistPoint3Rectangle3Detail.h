// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:50)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_DETAIL_H

#include "DistPoint3Rectangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"  

template <typename Real>
Mathematics::DistPoint3Rectangle3<Real>
	::DistPoint3Rectangle3(const Vector3D& point,const Rectangle3& rectangle)
	:ParentType{}, mPoint{ point }, mRectangle{ rectangle }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Rectangle3<Real>
	::GetPoint() const
{
    return mPoint;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistPoint3Rectangle3<Real>
	::GetRectangle() const
{
    return mRectangle;
}

template <typename Real>
typename const Mathematics::DistPoint3Rectangle3<Real>::DistanceResult Mathematics::DistPoint3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	auto diff = mRectangle.GetCenter() - mPoint;
	auto b0 = Vector3DTools::DotProduct(diff,mRectangle.GetAxis(0));
	auto b1 = Vector3DTools::DotProduct(diff, mRectangle.GetAxis(1));
	auto s0 = -b0;
	auto s1 = -b1;
	auto sqrDistance = Vector3DTools::VectorMagnitudeSquared(diff);

    if (s0 < -mRectangle.GetExtent(0))
    {
		s0 = -mRectangle.GetExtent(0);
    }
	else if (s0 > mRectangle.GetExtent(0))
    {
		s0 = mRectangle.GetExtent(0);
    }
    sqrDistance += s0*(s0 + ((Real)2)*b0);

	if (s1 < -mRectangle.GetExtent(1))
    {
		s1 = -mRectangle.GetExtent(1);
    }
	else if (s1 > mRectangle.GetExtent(1))
    {
		s1 = mRectangle.GetExtent(1);
    }
    sqrDistance += s1*(s1 + ((Real)2)*b1);

    // Account for numerical round-off error.
    if (sqrDistance < Real{})
    {
        sqrDistance = Real{};
    }

    mClosestPoint0 = mPoint;
	mClosestPoint1 = mRectangle.GetCenter() + s0*mRectangle.GetAxis(0) + s1*mRectangle.GetAxis(1);
    mRectCoord[0] = s0;
    mRectCoord[1] = s1;

	return DistanceResult{ sqrDistance, Real{}, mClosestPoint0, mClosestPoint1 };

}

template <typename Real>
typename const Mathematics::DistPoint3Rectangle3<Real>::DistanceResult Mathematics::DistPoint3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t*lhsVelocity;
	auto movedCenter = mRectangle.GetCenter() + t*rhsVelocity;
	Rectangle3 movedRectangle{ movedCenter, mRectangle.GetAxis(0), mRectangle.GetAxis(1), mRectangle.GetExtent(0), mRectangle.GetExtent(1) };
	return DistPoint3Rectangle3<Real>{ movedPoint, movedRectangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistPoint3Rectangle3<Real>
	::GetRectangleCoordinate(int i) const
{
    return mRectCoord[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_DETAIL_H
