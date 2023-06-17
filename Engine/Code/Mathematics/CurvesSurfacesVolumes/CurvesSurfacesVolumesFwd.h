///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_FWD_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_FWD_H

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingleCurve2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingleCurve3;

    template <typename Real>
    class BezierCurve2;

    template <typename Real>
    class BezierCurve3;

    template <typename Real>
    class BSplineBasis;

    template <typename Real>
    class BSplineCurve2;

    template <typename Real>
    class BSplineCurve3;

    template <typename Real>
    class BSplineFitBasis;

    template <typename Real>
    class BSplineCurveFit;

    template <typename Real>
    class RiemannianGeodesic;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Surface;

    template <typename Real>
    class ParametricSurface;

    template <typename Real>
    class BSplineRectangle;

    template <typename Real, typename TVector>
    class BSplineReduction;

    template <typename Real>
    class BSplineSurfaceFit;

    template <typename Real>
    class BSplineVolume;

    template <typename Real>
    class PolynomialCurve2;

    template <typename Real>
    class PolynomialCurve3;

    template <typename Real>
    class CubicPolynomialCurve2;

    template <typename Real>
    class CubicPolynomialCurve3;

    template <typename Real>
    class EllipsoidGeodesic;

    template <typename Real>
    class ImplicitSurface;

    template <typename Real>
    class MultipleCurve2;

    template <typename Real>
    class MultipleCurve3;

    template <typename Real>
    class NaturalSpline1;

    template <typename Real>
    class NaturalSpline2;

    template <typename Real>
    class NaturalSpline3;

    template <typename Real>
    class NURBSCurve2;

    template <typename Real>
    class NURBSCurve3;

    template <typename Real>
    class QuadricSurface;

    template <typename Real>
    class TCBSpline2;

    template <typename Real>
    class TCBSpline3;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_FWD_H