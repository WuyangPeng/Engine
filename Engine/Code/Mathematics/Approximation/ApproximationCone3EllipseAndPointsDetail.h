/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 13:35)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_DETAIL_H

#include "ApproximationCone3EllipseAndPoints.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/Algebra/Minimize1.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationCone3EllipseAndPoints<Real>::ApproximationCone3EllipseAndPoints() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCone3EllipseAndPoints<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3EllipseAndPoints<Real>::Cone3 Mathematics::ApproximationCone3EllipseAndPoints<Real>::Fit(const Ellipse3& ellipse, const Vector3Container& points, ApproximationCone3EllipseAndPointsControl control)
{
    ASSERT_FAIL_THROW_EXCEPTION(control.ValidParameters(), SYSTEM_TEXT("无效的控制参数。"))

    Real sigma0{};
    Real sigma1{};

    auto f = [&ellipse, &points, &sigma0, &sigma1, &control](const Real& theta) {
        const auto cone = ComputeCone(theta, sigma0, sigma1, ellipse);

        Real error{};
        for (const auto& point : points)
        {
            const auto diff = point - cone.GetRay().GetOrigin();
            auto dot = Dot(cone.GetRay().GetDirection(), diff);
            if (dot >= Real{})
            {
                auto sqrLen = Dot(diff, diff);
                auto quad = dot * dot - cone.GetCosAngleSqr() * sqrLen;
                auto term = quad * quad;
                error += term;
            }
            else
            {
                error += control.GetPenalty();
            }
        }

        error = std::sqrt(error) / boost::numeric_cast<Real>(points.size());
        return error;
    };

    Algebra::Minimize1<Real> minimizer(f,
                                       control.GetMaxSubdivisions(),
                                       control.GetMaxBisections(),
                                       control.GetEpsilon(),
                                       control.GetTolerance());
    auto t0 = boost::numeric_cast<Real>(control.GetPadding());
    auto t1 = Math::GetHalfPI() - control.GetPadding();
    Real tMin{};
    Real fMin{};
    auto minError = -Math::GetValue(1);
    Cone3 minCone{};

    sigma0 = Math::GetValue(1);
    sigma1 = Math::GetValue(1);
    minimizer.GetMinimum(t0, t1, tMin, fMin);
    if (t0 < tMin && tMin < t1)
    {
        if (Math::Approximate(minError, -Math::GetValue(1)) || fMin < minError)
        {
            minError = fMin;
            minCone = ComputeCone(tMin, sigma0, sigma1, ellipse);
        }
    }

    sigma0 = Math::GetValue(1);
    sigma1 = -Math::GetValue(1);
    minimizer.GetMinimum(t0, t1, tMin, fMin);
    if (t0 < tMin && tMin < t1)
    {
        if (Math::Approximate(minError, -Math::GetValue(1)) || fMin < minError)
        {
            minError = fMin;
            minCone = ComputeCone(tMin, sigma0, sigma1, ellipse);
        }
    }

    sigma0 = -Math::GetValue(1);
    sigma1 = Math::GetValue(1);
    minimizer.GetMinimum(t0, t1, tMin, fMin);
    if (t0 < tMin && tMin < t1)
    {
        if (Math::Approximate(minError, -Math::GetValue(1)) || fMin < minError)
        {
            minError = fMin;
            minCone = ComputeCone(tMin, sigma0, sigma1, ellipse);
        }
    }

    sigma0 = -Math::GetValue(1);
    sigma1 = -Math::GetValue(1);
    minimizer.GetMinimum(t0, t1, tMin, fMin);
    if (t0 < tMin && tMin < t1)
    {
        if (Math::Approximate(minError, -Math::GetValue(1)) || fMin < minError)
        {
            minError = fMin;
            minCone = ComputeCone(tMin, sigma0, sigma1, ellipse);
        }
    }

    ASSERT_FAIL_THROW_EXCEPTION(!Math::Approximate(minError, -Math::GetValue(1)), SYSTEM_TEXT("找不到合适的圆锥体。"))

    return minCone;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3EllipseAndPoints<Real>::Cone3 Mathematics::ApproximationCone3EllipseAndPoints<Real>::ComputeCone(Real theta, Real sigma0, Real sigma1, const Ellipse3& ellipse)
{
    const auto& c = ellipse.GetCenter();
    const auto& n = ellipse.GetNormal();
    const auto& u = ellipse.GetAxis(0);
    const auto& a = ellipse.GetExtent(0);
    const auto& b = ellipse.GetExtent(1);
    const auto bDivA = b / a;
    const auto eSqr = std::max(Real{}, Math::GetValue(1) - bDivA * bDivA);
    const auto omeSqr = Math::GetValue(1) - eSqr;
    const auto e = std::sqrt(eSqr);

    const auto snTheta = std::sin(theta);
    const auto csTheta = std::cos(theta);
    const auto snPhi = sigma0 * e * csTheta;
    const auto snPhiSqr = snPhi * snPhi;
    const auto csPhi = sigma1 * std::sqrt(std::max(Real{}, Math::GetValue(1) - snPhiSqr));
    const auto h = a * omeSqr * csTheta / (snTheta * std::fabs(csPhi));
    const auto d = csPhi * n + snPhi * u;
    const auto snThetaSqr = snTheta * snTheta;
    const auto csThetaSqr = csTheta * csTheta;
    const auto q = c - ((h * snPhi * snThetaSqr) / (csThetaSqr - snPhiSqr)) * u;
    const auto k = q - h * d;

    Cone3 cone{};
    cone.MakeInfiniteCone();
    cone.SetAngle(theta);
    cone.SetRay(Ray{ k, d });
    return cone;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_DETAIL_H
