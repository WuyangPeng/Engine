///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:25)

#ifndef MATHEMATICS_APPROXIMATION_FWD_H
#define MATHEMATICS_APPROXIMATION_FWD_H

namespace Mathematics
{
    template <typename Real>
    class QuadraticFit2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticCircleFit2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CircleFit2;

    template <typename Real>
    class EllipseByArcs2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticSphereFit3;

    template <typename Real>
    class QuadraticFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SphereFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightLineFit2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit3;

    template <typename Real>
    class GaussPointsFit2;

    template <typename Real>
    class GaussPointsFit3;

    template <typename Real>
    class ParaboloidFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightPlaneFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalPlaneFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CylinderFit3;

    template <typename Real>
    class EllipseFit2;

    template <typename Real>
    class EllipsoidFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatCircleFit3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatArcFit3;

    template <typename Real>
    class PolynomialFit2;

    template <typename Real>
    class PolynomialFit3;

    template <typename Real>
    class PolynomialFit4;

    template <typename Real>
    class PolynomialFit2Powers;

    template <typename Real>
    class PolynomialFit3Powers;

    template <typename Real>
    class PolynomialFit4Powers;

    template <typename Real>
    class PolynomialSamplesPower;

    template <typename Real, int S>
    class PolynomialFitPowersData;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCircle2;

    template <typename Real, typename ObservationType>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationQuery;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationHeightLine2;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationGaussian2;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationGaussian3;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationEllipse2;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3EllipseAndPoints;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3ExtractEllipses;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationConvexQuadByRect;
}

#endif  // MATHEMATICS_APPROXIMATION_FWD_H