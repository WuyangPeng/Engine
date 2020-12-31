///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 15:48)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H

#include "OrthogonalLineFit2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::OrthogonalLineFit2<Real>::OrthogonalLineFit2(const Points& points)
    : m_Line{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalLineFit2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::OrthogonalLineFit2<Real>::GetLine2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Line;
}

// static
template <typename Real>
typename Mathematics::OrthogonalLineFit2<Real>::Line2 Mathematics::OrthogonalLineFit2<Real>::Calculate(const Points& points)
{
    // 计算点的平均值。
    Vector2D origin{};
    for (const auto& point : points)
    {
        origin += point;
    }

    origin /= boost::numeric_cast<Real>(points.size());

    // 计算点的协方差矩阵。
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    for (const auto& point : points)
    {
        auto diff = point - origin;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumYY += diff.GetY() * diff.GetY();
    }

    sumXX /= boost::numeric_cast<Real>(points.size());
    sumXY /= boost::numeric_cast<Real>(points.size());
    sumYY /= boost::numeric_cast<Real>(points.size());

    // 建立 eigensolver.
    EigenDecomposition<Real> eigenSystem{ 2 };
    eigenSystem(0, 0) = sumYY;
    eigenSystem(0, 1) = -sumXY;
    eigenSystem(1, 0) = -sumXY;
    eigenSystem(1, 1) = sumXX;

    // 计算特征值，最小的特征是在最后的位置。
    eigenSystem.Solve(false);

    // 对于最佳拟合线的单位长度方向。
    const auto direction = eigenSystem.GetEigenvector2(1);

    return Line2{ origin, direction };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H
