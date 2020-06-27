// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:53)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H

#include "EllipsoidGeodesic.h"

namespace Mathematics
{

template <typename Real>
EllipsoidGeodesic<Real>::EllipsoidGeodesic (Real xExtent, Real yExtent,Real zExtent)
	: RiemannianGeodesic<Real>{ 2 }
{
    mXExtent = xExtent;
    mYExtent = yExtent;
    mZExtent = zExtent;
}

template <typename Real>
EllipsoidGeodesic<Real>::~EllipsoidGeodesic ()
{
}

template <typename Real>
Vector3D<Real> EllipsoidGeodesic<Real>::ComputePosition (const VariableLengthVector<Real>& point)
{
	auto cos0 = Math<Real>::Cos(point[0]);
	auto sin0 = Math<Real>::Sin(point[0]);
	auto cos1 = Math<Real>::Cos(point[1]);
	auto sin1 = Math<Real>::Sin(point[1]);

	return Vector3D<Real>{ mXExtent*cos0*sin1, mYExtent*sin0*sin1, mZExtent*cos1 };
}

template <typename Real>
void EllipsoidGeodesic<Real>::ComputeMetric(const VariableLengthVector<Real>& point)
{
	auto cos0 = Math<Real>::Cos(point[0]);
	auto sin0 = Math<Real>::Sin(point[0]);
	auto cos1 = Math<Real>::Cos(point[1]);
	auto sin1 = Math<Real>::Sin(point[1]);

	Vector3D<Real> der0{ -mXExtent * sin0*sin1, mYExtent*cos0*sin1, Math<Real>::sm_Zero };
	Vector3D<Real> der1{ mXExtent*cos0*cos1,  mYExtent*sin0*cos1,-mZExtent * sin1 };

	mMetric[0][0] = Vector3DTools<Real>::DotProduct(der0,der0);
	mMetric[0][1] = Vector3DTools<Real>::DotProduct(der0,der1);
    mMetric[1][0] = mMetric[0][1];
	mMetric[1][1] = Vector3DTools<Real>::DotProduct(der1,der1);
}

template <typename Real>
void EllipsoidGeodesic<Real>::ComputeChristoffel1 (const VariableLengthVector<Real>& point)
{
	auto cos0 = Math<Real>::Cos(point[0]);
	auto sin0 = Math<Real>::Sin(point[0]);
	auto cos1 = Math<Real>::Cos(point[1]);
	auto sin1 = Math<Real>::Sin(point[1]);

	Vector3D<Real> der0{ -mXExtent * sin0*sin1, mYExtent*cos0*sin1, Math<Real>::sm_Zero };

	Vector3D<Real> der1{ mXExtent*cos0*cos1,  mYExtent*sin0*cos1,-mZExtent * sin1 };

	Vector3D<Real> der00{ -mXExtent * cos0*sin1, -mYExtent * sin0*sin1, Math<Real>::sm_Zero };

	Vector3D<Real> der01{ -mXExtent * sin0*cos1, mYExtent*cos0*cos1, Math<Real>::sm_Zero };

	Vector3D<Real> der11{ -mXExtent * cos0*sin1, -mYExtent * sin0*sin1,-mZExtent * cos1 };

	mChristoffel1[0][0][0] = Vector3DTools<Real>::DotProduct(der00,der0);
	mChristoffel1[0][0][1] = Vector3DTools<Real>::DotProduct(der01,der0);
    mChristoffel1[0][1][0] = mChristoffel1[0][0][1];
	mChristoffel1[0][1][1] = Vector3DTools<Real>::DotProduct(der11,der0);

	mChristoffel1[1][0][0] = Vector3DTools<Real>::DotProduct(der00,der1);
	mChristoffel1[1][0][1] = Vector3DTools<Real>::DotProduct(der01,der1);
    mChristoffel1[1][1][0] = mChristoffel1[1][0][1];
	mChristoffel1[1][1][1] = Vector3DTools<Real>::DotProduct(der11,der1);
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H