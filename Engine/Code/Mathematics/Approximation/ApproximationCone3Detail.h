/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 10:04)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_DETAIL_H

#include "ApproximationCone3.h"
#include "ApproximationHeightLine2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/NumericalAnalysis/LevenbergMarquardtMinimizer.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationCone3<Real>::ApproximationCone3() noexcept
    : points{},
      /// F[i](V,W) = D^T * (I - W * W^T) * D, D = V - X[i], P = (V,W)
      fFunction{ [this](const VariableLengthVector& p, VariableLengthVector& f) {
          const auto numPoints = boost::numeric_cast<int>(points.size());
          const Vector3 v{ p[0], p[1], p[2] };
          const Vector3 w{ p[3], p[4], p[5] };
          for (auto i = 0; i < numPoints; ++i)
          {
              const auto delta = v - points.at(i);
              auto deltaDotW = Dot(delta, w);
              f[i] = Dot(delta, delta) - deltaDotW * deltaDotW;
          }
      } },
      /// dF[i]/dV = 2 * (D - Dot(W, D) * W)
      /// dF[i]/dW = -2 * Dot(W, D) * D
      jFunction{ [this](const VariableLengthVector& p, VariableMatrix& j) {
          const auto numPoints = boost::numeric_cast<int>(points.size());
          const Vector3 v{ p[0], p[1], p[2] };
          const Vector3 w{ p[3], p[4], p[5] };
          for (auto row = 0; row < numPoints; ++row)
          {
              const auto delta = v - points.at(row);
              auto deltaDotW = Dot(delta, w);
              auto temp0 = delta - deltaDotW * w;
              auto temp1 = deltaDotW * delta;
              for (auto col = 0; col < 3; ++col)
              {
                  j(row, col) = Math::GetValue(2) * temp0[col];
                  j(row, col + 3) = -Math::GetValue(2) * temp1[col];
              }
          }
      } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCone3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3<Real>::GaussNewtonMinimizerResult Mathematics::ApproximationCone3<Real>::operator()(const Vector3Container& aPoints, int maxIterations, Real updateLengthTolerance, Real errorDifferenceTolerance, bool useConeInputAsInitialGuess, Vector3& coneVertex, Vector3& coneAxis, Real& coneAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    points = aPoints;
    GaussNewtonMinimizer<Real> minimizer{ 6, boost::numeric_cast<int>(points.size()), fFunction, jFunction };

    if (useConeInputAsInitialGuess)
    {
        Normalize(coneAxis);
    }
    else
    {
        ComputeInitialCone(coneVertex, coneAxis, coneAngle);
    }

    /// 圆锥体顶点的初始猜测。
    VariableLengthVector initial{ 6 };
    initial[0] = coneVertex[0];
    initial[1] = coneVertex[1];
    initial[2] = coneVertex[2];

    /// 加权圆锥轴的初始猜测。
    auto coneCosAngle = std::cos(coneAngle);
    initial[3] = coneAxis[0] / coneCosAngle;
    initial[4] = coneAxis[1] / coneCosAngle;
    initial[5] = coneAxis[2] / coneCosAngle;

    auto result = minimizer(initial, maxIterations, updateLengthTolerance, errorDifferenceTolerance);

    /// 没有对结果进行任何测试。
    /// 收敛，因此我们返回了圆锥体的一些估计值。
    /// 当result.converged为false时，调用者可以决定如何响应。
    for (auto i = 0; i < 3; ++i)
    {
        const auto minLocation = result.GetMinLocation();
        coneVertex[i] = minLocation[i];
        coneAxis[i] = minLocation[i + 3];
    }

    /// 我们知道coneCosAngle是非负的。
    /// std::min调用防止舍入错误导致数字略大于1。
    /// 夹紧确保std::acos不会返回NaN。

    coneCosAngle = std::min(Math::GetValue(1) / Normalize(coneAxis), Math::GetValue(1));
    coneAngle = std::acos(coneCosAngle);

    points.clear();
    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3<Real>::LevenbergMarquardtMinimizerResult Mathematics::ApproximationCone3<Real>::operator()(const Vector3Container& aPoints, int maxIterations, Real updateLengthTolerance, Real errorDifferenceTolerance, Real lambdaFactor, Real lambdaAdjust, int maxAdjustments, bool useConeInputAsInitialGuess, Vector3& coneVertex, Vector3& coneAxis, Real& coneAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    points = aPoints;
    LevenbergMarquardtMinimizer<Real> minimizer{ 6, boost::numeric_cast<int>(points.size()), fFunction, jFunction };

    if (useConeInputAsInitialGuess)
    {
        Normalize(coneAxis);
    }
    else
    {
        ComputeInitialCone(coneVertex, coneAxis, coneAngle);
    }

    /// 圆锥体顶点的初始猜测。
    VariableLengthVector initial{ 6 };
    initial[0] = coneVertex[0];
    initial[1] = coneVertex[1];
    initial[2] = coneVertex[2];

    /// 加权圆锥轴的初始猜测。
    auto coneCosAngle = std::cos(coneAngle);
    initial[3] = coneAxis[0] / coneCosAngle;
    initial[4] = coneAxis[1] / coneCosAngle;
    initial[5] = coneAxis[2] / coneCosAngle;

    auto result = minimizer(initial, maxIterations, updateLengthTolerance, errorDifferenceTolerance, lambdaFactor, lambdaAdjust, maxAdjustments);

    /// 没有对结果进行任何测试。
    /// 收敛，因此我们返回了圆锥体的一些估计值。
    /// 当result.converged为false时，调用者可以决定如何响应。
    for (auto i = 0; i < 3; ++i)
    {
        const auto minLocation = result.GetMinLocation();
        coneVertex[i] = minLocation[i];
        coneAxis[i] = minLocation[i + 3];
    }

    /// 我们知道coneCosAngle是非负的。
    /// std::min调用防止舍入错误导致数字略大于1。
    /// 夹紧确保 std::acos不会返回NaN。

    coneCosAngle = std::min(Math::GetValue(1) / Normalize(coneAxis), Math::GetValue(1));
    coneAngle = std::acos(coneCosAngle);

    points.clear();
    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3<Real>::ComputeInitialCone(Vector3& coneVertex, Vector3& coneAxis, Real& coneAngle)
{
    /// 计算采样点的平均值。

    Vector3 center{};
    const auto tNumPoints = boost::numeric_cast<Real>(points.size());
    for (auto i = 0u; i < points.size(); ++i)
    {
        center += points.at(i);
    }
    center /= tNumPoints;

    /// 圆锥轴是根据ZZTZ估算的
    coneAxis = {};
    for (auto i = 0u; i < points.size(); ++i)
    {
        const auto delta = points.at(i) - center;
        coneAxis += delta * Dot(delta, delta);
    }
    Normalize(coneAxis);

    /// 计算点沿锥轴相对于C的有符号高度。
    /// 这些是点到线C+t*U上的投影。还计算点与线C+t*U的径向距离。
    std::vector<Algebra::Vector2<Real>> hrPairs(points.size());
    auto hMin = std::numeric_limits<Real>::max();
    auto hMax = -hMin;
    for (auto i = 0u; i < points.size(); ++i)
    {
        const auto delta = points.at(i) - center;
        auto h = Dot(coneAxis, delta);
        hMin = std::min(hMin, h);
        hMax = std::max(hMax, h);
        const auto projection = delta - Dot(coneAxis, delta) * coneAxis;
        auto r = Length(projection);
        hrPairs.at(i) = { h, r };
    }

    /// 径向距离被认为是高度的函数。
    /// 用一条线拟合(h,r)对：
    ///   r - rAverage = hrSlope * (h - hAverage)
    ApproximationHeightLine2<Real> fitter{};
    std::ignore = fitter.Fit(hrPairs);
    const auto& parameters = fitter.GetParameters();
    auto hAverage = parameters.first[0];
    auto rAverage = parameters.first[1];
    auto hrSlope = parameters.second[0];

    /// 如果U是定向的，使得r随着h的增加而增加，则U是正确的锥轴估计。
    /// 但是，如果r随着h的增加而减小，则-U是正确的锥轴估计值。
    if (hrSlope < Real{})
    {
        coneAxis = -coneAxis;
        hrSlope = -hrSlope;
        std::swap(hMin, hMax);
        hMin = -hMin;
        hMax = -hMax;
    }

    /// 计算点的径向距离极值。
    auto rMin = rAverage + hrSlope * (hMin - hAverage);
    auto rMax = rAverage + hrSlope * (hMax - hAverage);
    const auto hRange = hMax - hMin;
    auto rRange = rMax - rMin;

    /// 使用三角法和直角三角形，计算锥角的正切函数。
    auto tanAngle = rRange / hRange;
    coneAngle = std::atan2(rRange, hRange);

    /// 计算圆锥体顶点。
    auto offset = rMax / tanAngle - hMax;
    coneVertex = center - offset * coneAxis;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_DETAIL_H
