///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:22)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H

#include "QuadraticFit2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticFit2<Real>::QuadraticFit2(const Points& points)
    : coeff{}, eigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::QuadraticFit2<Real>::Calculate(const Points& points)
{
    EigenDecomposition<Real> eigenSystem{ eigenSystemSize };

    const auto numPoints = boost::numeric_cast<Real>(points.size());

    for (const auto& point : points)
    {
        const auto x = point.GetX();
        const auto y = point.GetY();
        const auto xSquare = x * x;
        const auto ySquare = y * y;
        const auto xMultiplyY = x * y;
        const auto xCube = x * xSquare;
        const auto xMultiplyYSquare = x * ySquare;
        const auto xSquareMultiplyY = x * xMultiplyY;
        const auto yCube = y * ySquare;
        const auto xQuadruplicate = x * xCube;
        const auto xSquareMultiplyYSquare = x * xMultiplyYSquare;
        const auto xCubeMultiplyY = x * xSquareMultiplyY;
        const auto yQuadruplicate = y * yCube;
        const auto xMultiplyYCube = x * yCube;

        eigenSystem(0, 1) += x;
        eigenSystem(0, 2) += y;
        eigenSystem(0, 3) += xSquare;
        eigenSystem(0, 4) += ySquare;
        eigenSystem(0, 5) += xMultiplyY;
        eigenSystem(1, 3) += xCube;
        eigenSystem(1, 4) += xMultiplyYSquare;
        eigenSystem(1, 5) += xSquareMultiplyY;
        eigenSystem(2, 4) += yCube;
        eigenSystem(3, 3) += xQuadruplicate;
        eigenSystem(3, 4) += xSquareMultiplyYSquare;
        eigenSystem(3, 5) += xCubeMultiplyY;
        eigenSystem(4, 4) += yQuadruplicate;
        eigenSystem(4, 5) += xMultiplyYCube;
    }

    eigenSystem(0, 0) = numPoints;
    eigenSystem(1, 1) = eigenSystem(0, 3);
    eigenSystem(1, 2) = eigenSystem(0, 5);
    eigenSystem(2, 2) = eigenSystem(0, 4);
    eigenSystem(2, 3) = eigenSystem(1, 5);
    eigenSystem(2, 5) = eigenSystem(1, 4);
    eigenSystem(5, 5) = eigenSystem(3, 4);

    for (auto row = 0; row < eigenSystemSize; ++row)
    {
        for (auto col = 0; col < row; ++col)
        {
            eigenSystem(row, col) = eigenSystem(col, row);
        }
    }

    for (auto row = 0; row < eigenSystemSize; ++row)
    {
        for (auto col = 0; col < eigenSystemSize; ++col)
        {
            eigenSystem(row, col) /= numPoints;
        }
    }

    eigenSystem.Solve(true);

    coeff = eigenSystem.GetEigenvector(0);

    // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
    // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
    eigenValue = Math::FAbs(eigenSystem.GetEigenvalue(0));
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuadraticFit2<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= eigenValue)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::QuadraticFit2<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coeff;
}

template <typename Real>
Real Mathematics::QuadraticFit2<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return eigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H
