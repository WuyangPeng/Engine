/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 16:58)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_DETAIL_H

#include "ApproximationCircle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationCircle2<Real>::ApproximationCircle2() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCircle2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCircle2<Real>::FitUsingSquaredLengths(const Vector2Container& points, Circle2Type& circle)
{
    const auto numPoints = boost::numeric_cast<int>(points.size());

    /// 计算数据点的平均值。
    Vector2Type a{};
    for (auto i = 0; i < numPoints; ++i)
    {
        a += points.at(i);
    }
    auto invNumPoints = MathType::GetValue(1) / MathType::GetValue(numPoints);
    a *= invNumPoints;

    /// 计算Y[i] = X[i]-A和线性系统M*(C-A) = R的右侧R的协方差矩阵M。
    Real m00{};
    Real m01{};
    Real m11{};
    Vector2Type r{};
    for (auto i = 0; i < numPoints; ++i)
    {
        auto y = points.at(i) - a;
        auto y0Y0 = y[0] * y[0];
        auto y0Y1 = y[0] * y[1];
        auto y1Y1 = y[1] * y[1];
        m00 += y0Y0;
        m01 += y0Y1;
        m11 += y1Y1;
        r += (y0Y0 + y1Y1) * y;
    }
    r *= MathType::GetRational(1, 2);

    /// 求解中心C的线性系统M*(C-A) = R。
    auto det = m00 * m11 - m01 * m01;
    if (!MathType::Approximate(det, Real{}))
    {
        circle.SetCenterX(a[0] + (m11 * r[0] - m01 * r[1]) / det);
        circle.SetCenterY(a[1] + (m00 * r[1] - m01 * r[0]) / det);
        Real rSqr{};
        for (auto i = 0; i < numPoints; ++i)
        {
            const auto delta = points.at(i) - circle.GetCenter().GetVector();
            rSqr += Dot(delta, delta);
        }
        rSqr *= invNumPoints;
        circle.SetRadius(std::sqrt(rSqr));
        return true;
    }
    else
    {
        circle.SetCircle({ Real{}, Real{} }, Real{});

        return false;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationCircle2<Real>::FitUsingLengths(const Vector2Container& points, int maxIterations, bool initialCenterIsAverage, Circle2Type& circle, Real epsilon)
{
    const auto numPoints = boost::numeric_cast<int>(points.size());

    /// 计算数据点的平均值。
    auto average = points.at(0);
    for (auto i = 1; i < numPoints; ++i)
    {
        average += points.at(i);
    }
    auto invNumPoints = MathType::GetValue(1) / static_cast<Real>(numPoints);
    average *= invNumPoints;

    /// 对中心的初步猜测。
    if (initialCenterIsAverage)
    {
        circle.SetCenter(average);
    }

    auto epsilonSqr = epsilon * epsilon;
    auto iteration = 0;
    for (; iteration < maxIterations; ++iteration)
    {
        /// 更新迭代。
        const auto current = circle.GetCenter().GetVector();

        /// 计算平均值 L, dL/da, dL/db.
        Real lenAverage{};
        auto derLenAverage = Vector2Type::GetZero();
        for (auto i = 0; i < numPoints; ++i)
        {
            const auto diff = points.at(i) - circle.GetCenter().GetVector();
            auto length = Length(diff);
            if (length > Real{})
            {
                lenAverage += length;
                auto invLength = MathType::GetValue(1) / length;
                derLenAverage -= invLength * diff;
            }
        }
        lenAverage *= invNumPoints;
        derLenAverage *= invNumPoints;

        circle.SetCenter(average + lenAverage * derLenAverage);
        circle.SetRadius(lenAverage);

        const auto diff = circle.GetCenter().GetVector() - current;
        auto diffSqrLen = Dot(diff, diff);
        if (diffSqrLen <= epsilonSqr)
        {
            break;
        }
    }

    return ++iteration;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_DETAIL_H
