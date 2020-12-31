///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 10:22)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H

#include "QuadraticCircleFit2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticCircleFit2<Real>::QuadraticCircleFit2(const Points& points)
    : m_Center{}, m_Radius{}, m_EigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticCircleFit2<Real>::Calculate(const Points& points)
{
    EigenDecomposition<Real> eigenSystem{ sm_EigenSystemSize };

    auto numPoints = static_cast<Real>(points.size());

    for (const auto& value : points)
    {
        auto x = value.GetX();
        auto y = value.GetY();
        auto xSquare = x * x;
        auto ySquare = y * y;
        auto xMultiplyY = x * y;
        auto rSquare = xSquare + ySquare;
        auto xMultiplyRSquare = x * rSquare;
        auto yMultiplyRSquare = y * rSquare;
        auto rQuadruplicate = rSquare * rSquare;

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

    for (auto row = 0; row < sm_EigenSystemSize; ++row)
    {
        for (auto column = 0; column < row; ++column)
        {
            eigenSystem(row, column) = eigenSystem(column, row);
        }
    }

    for (auto row = 0; row < sm_EigenSystemSize; ++row)
    {
        for (auto column = 0; column < sm_EigenSystemSize; ++column)
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Center[0] = -(Math::GetRational(1, 2) * coeff[1]);
        m_Center[1] = -(Math::GetRational(1, 2) * coeff[2]);
        m_Radius = Math::Sqrt(Math::FAbs(m_Center.GetX() * m_Center.GetX() + m_Center.GetY() * m_Center.GetY() - coeff[0]));

#include STSTEM_WARNING_POP

        // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
        // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
        m_EigenValue = Math::FAbs(eigenSystem.GetEigenvalue(0));
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
    if (Math::GetValue(0) < m_Radius && Math::GetValue(0) <= m_EigenValue)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::QuadraticCircleFit2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_EigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_ACHIEVE_H
