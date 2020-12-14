///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 15:57)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_ACHIEVE_H

#include "OrthogonalLineFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::OrthogonalLineFit3<Real>::OrthogonalLineFit3(const Points& points)
    : m_Line{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalLineFit3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::OrthogonalLineFit3<Real>::GetLine3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Line;
}

// static
template <typename Real>
Mathematics::Line3<Real> Mathematics::OrthogonalLineFit3<Real>::Calculate(const Points& points)
{
    // 计算点的平均值。
    Vector3D origin{};
    for (const auto& point : points)
    {
        origin += point;
    }

    origin /= boost::numeric_cast<Real>(points.size());

    // 计算点的协方差矩阵。
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumXZ = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    auto sumYZ = Math::GetValue(0);
    auto sumZZ = Math::GetValue(0);

    for (const auto& point : points)
    {
        auto diff = point - origin;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumXZ += diff.GetX() * diff.GetZ();
        sumYY += diff.GetY() * diff.GetY();
        sumYZ += diff.GetY() * diff.GetZ();
        sumZZ += diff.GetZ() * diff.GetZ();
    }

    sumXX /= boost::numeric_cast<Real>(points.size());
    sumXY /= boost::numeric_cast<Real>(points.size());
    sumXZ /= boost::numeric_cast<Real>(points.size());
    sumYY /= boost::numeric_cast<Real>(points.size());
    sumYZ /= boost::numeric_cast<Real>(points.size());
    sumZZ /= boost::numeric_cast<Real>(points.size());

    // 建立 eigensolver.
    EigenDecomposition<Real> eigenSystem{ 3 };
    eigenSystem(0, 0) = sumYY + sumZZ;
    eigenSystem(0, 1) = -sumXY;
    eigenSystem(0, 2) = -sumXZ;
    eigenSystem(1, 0) = eigenSystem(0, 1);
    eigenSystem(1, 1) = sumXX + sumZZ;
    eigenSystem(1, 2) = -sumYZ;
    eigenSystem(2, 0) = eigenSystem(0, 2);
    eigenSystem(2, 1) = eigenSystem(1, 2);
    eigenSystem(2, 2) = sumXX + sumYY;

    // 计算特征值，最小的特征是在最后的位置。
    eigenSystem.Solve(false);

    // 对于最佳拟合线的单位长度方向。
    const auto direction = eigenSystem.GetEigenvector3(2);

    return Line3{ origin, direction };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_ACHIEVE_H
