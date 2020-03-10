// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:57)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H

#include "Mathematics/MathematicsDll.h"

#include "RiemannianGeodesic.h"
#include "BSplineRectangle.h"

namespace Mathematics
{
	template <typename Real>
	class  BSplineGeodesic : public RiemannianGeodesic<Real>
	{
	public:
		BSplineGeodesic(const BSplineRectangle<Real>& spline);
		virtual ~BSplineGeodesic();

		virtual void ComputeMetric(const VariableLengthVector<Real>& point);
		virtual void ComputeChristoffel1(const VariableLengthVector<Real>& point);

	private:
		using RiemannianGeodesic<Real>::mMetric;
		using RiemannianGeodesic<Real>::mChristoffel1;

		const BSplineRectangle<Real>* mSpline;
	};

	using BSplineGeodesicf = BSplineGeodesic<float>;
	using BSplineGeodesicd = BSplineGeodesic<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H
