///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:21)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H

#include "QuadraticCircleFit2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticCircleFit2<Real>::QuadraticCircleFit2(const Points& points)
    : center{}, radius{}, eigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::QuadraticCircleFit2<Real>::Calculate(const Points& points)
{
    EigenDecomposition<Real> eigenSystem{ eigenSystemSize };

    const auto numPoints = static_cast<Real>(points.size());

    for (const auto& value : points)
    {
        const auto x = value.GetX();
        const auto y = value.GetY();
        const auto xSquare = x * x;
        const auto ySquare = y * y;
        const auto xMultiplyY = x * y;
        const auto rSquare = xSquare + ySquare;
        const auto xMultiplyRSquare = x * rSquare;
        const auto yMultiplyRSquare = y * rSquare;
        const auto rQuadruplicate = rSquare * rSquare;

        eigenSystem(0, 1) += x;
        eigenSystem(0, 2) += y;
        eigenSystem(0, 3) += rSquare;
        eigenSystem(1, 1) += xSquare;
        eigenSystem(1, 2) += xMultiplyY;
        eigenSystem(1, 3) += xMultiplyRSquare;
        eigenSystem(2, 2) += ySquare;
        eigenSystem(2, 3) += yMultiplyRSquare;
        eigenSystem(3, 3) += rQuadruplicate;
    }

    eigenSystem(0, 0) = numPoints;

    for (auto row = 0; row < eigenSystemSize; ++row)
    {
        for (auto column = 0; column < row; ++column)
        {
            eigenSystem(row, column) = eigenSystem(column, row);
        }
    }

    for (auto row = 0; row < eigenSystemSize; ++row)
    {
        for (auto column = 0; column < eigenSystemSize; ++column)
        {
            eigenSystem(row, column) /= numPoints;
        }
    }

    eigenSystem.Solve(true);

    auto eigenVector = eigenSystem.GetEigenvector(0);
    // 当心除零
    if (Math::GetZeroTolerance() < Math::FAbs(eigenVector[3]))
    {
        auto inv = Math::GetValue(1) / eigenVector[3];

        std::array<Real, 3> coeff{ inv * eigenVector[0], inv * eigenVector[1], inv * eigenVector[2] };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        center[0] = -(Math::GetRational(1, 2) * coeff[1]);
        center[1] = -(Math::GetRational(1, 2) * coeff[2]);
        radius = Math::Sqrt(Math::FAbs(center.GetX() * center.GetX() + center.GetY() * center.GetY() - coeff[0]));

#include SYSTEM_WARNING_POP

        // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
        // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
        eigenValue = Math::FAbs(eigenSystem.GetEigenvalue(0));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuadraticCircleFit2<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) < radius && Math::GetValue(0) <= eigenValue)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::QuadraticCircleFit2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return eigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H
