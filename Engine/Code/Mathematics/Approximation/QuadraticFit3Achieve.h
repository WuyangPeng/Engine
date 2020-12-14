///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 11:04)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_ACHIEVE_H

#include "QuadraticFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticFit3<Real>::QuadraticFit3(const Points& points)
    : m_Coeff{}, m_EigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticFit3<Real>::Calculate(const Points& points)
{
    EigenDecomposition<Real> eigenSystem{ sm_EigenSystemSize };

    auto numPoints = boost::numeric_cast<Real>(points.size());

    for (const auto& point : points)
    {
        auto x = point.GetX();
        auto y = point.GetY();
        auto z = point.GetZ();
        auto x2 = x * x;
        auto y2 = y * y;
        auto z2 = z * z;
        auto xy = x * y;
        auto xz = x * z;
        auto yz = y * z;
        auto x3 = x * x2;
        auto xy2 = x * y2;
        auto xz2 = x * z2;
        auto x2y = x * xy;
        auto x2z = x * xz;
        auto xyz = x * y * z;
        auto y3 = y * y2;
        auto yz2 = y * z2;
        auto y2z = y * yz;
        auto z3 = z * z2;
        auto fX4 = x * x3;
        auto x2y2 = x * xy2;
        auto x2z2 = x * xz2;
        auto x3y = x * x2y;
        auto x3z = x * x2z;
        auto x2yz = x * xyz;
        auto y4 = y * y3;
        auto y2z2 = y * yz2;
        auto xy3 = x * y3;
        auto xy2z = x * y2z;
        auto y3z = y * y2z;
        auto fZ4 = z * z3;
        auto xyz2 = x * yz2;
        auto xz3 = x * z3;
        auto yz3 = y * z3;

        eigenSystem(0, 1) += x;
        eigenSystem(0, 2) += y;
        eigenSystem(0, 3) += z;
        eigenSystem(0, 4) += x2;
        eigenSystem(0, 5) += y2;
        eigenSystem(0, 6) += z2;
        eigenSystem(0, 7) += xy;
        eigenSystem(0, 8) += xz;
        eigenSystem(0, 9) += yz;
        eigenSystem(1, 4) += x3;
        eigenSystem(1, 5) += xy2;
        eigenSystem(1, 6) += xz2;
        eigenSystem(1, 7) += x2y;
        eigenSystem(1, 8) += x2z;
        eigenSystem(1, 9) += xyz;
        eigenSystem(2, 5) += y3;
        eigenSystem(2, 6) += yz2;
        eigenSystem(2, 9) += y2z;
        eigenSystem(3, 6) += z3;
        eigenSystem(4, 4) += fX4;
        eigenSystem(4, 5) += x2y2;
        eigenSystem(4, 6) += x2z2;
        eigenSystem(4, 7) += x3y;
        eigenSystem(4, 8) += x3z;
        eigenSystem(4, 9) += x2yz;
        eigenSystem(5, 5) += y4;
        eigenSystem(5, 6) += y2z2;
        eigenSystem(5, 7) += xy3;
        eigenSystem(5, 8) += xy2z;
        eigenSystem(5, 9) += y3z;
        eigenSystem(6, 6) += fZ4;
        eigenSystem(6, 7) += xyz2;
        eigenSystem(6, 8) += xz3;
        eigenSystem(6, 9) += yz3;
        eigenSystem(9, 9) += y2z2;
    }

    eigenSystem(0, 0) = numPoints;
    eigenSystem(1, 1) = eigenSystem(0, 4);
    eigenSystem(1, 2) = eigenSystem(0, 7);
    eigenSystem(1, 3) = eigenSystem(0, 8);
    eigenSystem(2, 2) = eigenSystem(0, 5);
    eigenSystem(2, 3) = eigenSystem(0, 9);
    eigenSystem(2, 4) = eigenSystem(1, 7);
    eigenSystem(2, 7) = eigenSystem(1, 5);
    eigenSystem(2, 8) = eigenSystem(1, 9);
    eigenSystem(3, 3) = eigenSystem(0, 6);
    eigenSystem(3, 4) = eigenSystem(1, 8);
    eigenSystem(3, 5) = eigenSystem(2, 9);
    eigenSystem(3, 7) = eigenSystem(1, 9);
    eigenSystem(3, 8) = eigenSystem(1, 6);
    eigenSystem(3, 9) = eigenSystem(2, 6);
    eigenSystem(7, 7) = eigenSystem(4, 5);
    eigenSystem(7, 8) = eigenSystem(4, 9);
    eigenSystem(7, 9) = eigenSystem(5, 8);
    eigenSystem(8, 8) = eigenSystem(4, 6);
    eigenSystem(8, 9) = eigenSystem(6, 7);
    eigenSystem(9, 9) = eigenSystem(5, 6);

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

    m_Coeff = eigenSystem.GetEigenvector(0);

    // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
    // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
    m_EigenValue = Math<Real>::FAbs(eigenSystem.GetEigenvalue(0));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuadraticFit3<Real>::IsValid() const noexcept
{
    if (Math<Real>::GetValue(0) <= m_EigenValue)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::QuadraticFit3<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff;
}

template <typename Real>
Real Mathematics::QuadraticFit3<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_EigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_ACHIEVE_H
