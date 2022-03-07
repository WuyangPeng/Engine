// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:42)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H

#include "BSplineGeodesic.h"

namespace Mathematics
{

template <typename Real>
BSplineGeodesic<Real>::BSplineGeodesic (const BSplineRectangle<Real>& spline)
	: RiemannianGeodesic<Real>{ 2 }, mSpline{ &spline }
{
}

template <typename Real>
BSplineGeodesic<Real>::~BSplineGeodesic ()
{
}

template <typename Real>
void BSplineGeodesic<Real>::ComputeMetric(const VariableLengthVector<Real>& point)
{
    auto der0 = mSpline->PU(point[0], point[1]);
	auto der1 = mSpline->PV(point[0], point[1]);

	mMetric[0][0] = Vector3Tools<Real>::DotProduct(der0,der0);
	mMetric[0][1] = Vector3Tools<Real>::DotProduct(der0,der1);
    mMetric[1][0] = mMetric[0][1];
	mMetric[1][1] = Vector3Tools<Real>::DotProduct(der1,der1);
}

template <typename Real>
void BSplineGeodesic<Real>::ComputeChristoffel1(const VariableLengthVector<Real>& point)
{
	auto der0 = mSpline->PU(point[0], point[1]);
	auto der1 = mSpline->PV(point[0], point[1]);
	auto der00 = mSpline->PUU(point[0], point[1]);
	auto der01 = mSpline->PUV(point[0], point[1]);
	auto der11 = mSpline->PVV(point[0], point[1]);

	mChristoffel1[0][0][0] = Vector3Tools<Real>::DotProduct(der00,der0);
	mChristoffel1[0][0][1] = Vector3Tools<Real>::DotProduct(der01,der0);
    mChristoffel1[0][1][0] = mChristoffel1[0][0][1];
	mChristoffel1[0][1][1] = Vector3Tools<Real>::DotProduct(der11,der0);

	mChristoffel1[1][0][0] = Vector3Tools<Real>::DotProduct(der00,der1);
	mChristoffel1[1][0][1] = Vector3Tools<Real>::DotProduct(der01,der1);
    mChristoffel1[1][1][0] = mChristoffel1[1][0][1];
	mChristoffel1[1][1][1] = Vector3Tools<Real>::DotProduct(der11,der1);
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H