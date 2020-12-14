///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 13:41)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_ACHIEVE_H

#include "GaussPointsFit2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::GaussPointsFit2<Real>::GaussPointsFit2(const PointsType& points)
    : m_Box{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GaussPointsFit2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box2<Real> Mathematics::GaussPointsFit2<Real>::GetBox2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::GaussPointsFit2<Real>::Calculate(const PointsType& points)
{
    auto numPoints = boost::numeric_cast<Real>(points.size());

    // 计算点的平均值。
    Vector2D center{};
    for (const auto& point : points)
    {
        center += point;
    }

    center /= numPoints;

    // 计算点的协方差矩阵。
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    for (const auto& point : points)
    {
        auto diff = point - center;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumYY += diff.GetY() * diff.GetY();
    }

    sumXX /= numPoints;
    sumXY /= numPoints;
    sumYY /= numPoints;

    constexpr const auto size = 2;

    // 建立 eigensolver.
    EigenDecomposition<Real> eigenSystem{ size };

    eigenSystem(0, 0) = sumXX;
    eigenSystem(0, 1) = sumXY;
    eigenSystem(1, 0) = sumXY;
    eigenSystem(1, 1) = sumYY;

    eigenSystem.Solve(true);

    std::array<Real, size> extent{};
    std::array<Vector2D, size> axis{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (auto i = 0; i < size; ++i)
    {
        extent[i] = eigenSystem.GetEigenvalue(i);
        axis[i] = eigenSystem.GetEigenvector2(i);
    }

    return Box2{ center, axis[0], axis[1], extent[0], extent[1] };

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_ACHIEVE_H
