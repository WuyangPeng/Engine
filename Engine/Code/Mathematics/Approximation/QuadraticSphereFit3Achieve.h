///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 18:35)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_SPHERE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_SPHERE_FIT3_ACHIEVE_H

#include "QuadraticSphereFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticSphereFit3<Real>::QuadraticSphereFit3(const Points& points)
    : center{}, radius{}, eigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticSphereFit3<Real>::Calculate(const Points& points)
{
    EigenDecomposition<Real> eigenSystem{ eigenSystemSize };

    const auto numPoints = boost::numeric_cast<Real>(points.size());

    for (const auto& point : points)
    {
        const auto x = point.GetX();
        const auto y = point.GetY();
        const auto z = point.GetZ();
        const auto x2 = x * x;
        const auto y2 = y * y;
        const auto z2 = z * z;
        const auto xy = x * y;
        const auto xz = x * z;
        const auto yz = y * z;
        const auto r2 = x2 + y2 + z2;
        const auto xr2 = x * r2;
        const auto yr2 = y * r2;
        const auto zr2 = z * r2;
        const auto r4 = r2 * r2;

        eigenSystem(0, 1) += x;
        eigenSystem(0, 2) += y;
        eigenSystem(0, 3) += z;
        eigenSystem(0, 4) += r2;
        eigenSystem(1, 1) += x2;
        eigenSystem(1, 2) += xy;
        eigenSystem(1, 3) += xz;
        eigenSystem(1, 4) += xr2;
        eigenSystem(2, 2) += y2;
        eigenSystem(2, 3) += yz;
        eigenSystem(2, 4) += yr2;
        eigenSystem(3, 3) += z2;
        eigenSystem(3, 4) += zr2;
        eigenSystem(4, 4) += r4;
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
    if (Math::GetZeroTolerance() < Math::FAbs(eigenVector[4]))
    {
        auto inv = Math::GetValue(1) / eigenVector[4];

        std::array<Real, 4> coeff{ inv * eigenVector[0], inv * eigenVector[1], inv * eigenVector[2], inv * eigenVector[3] };

        center[0] = -Math::GetRational(1, 2) * coeff.at(1);
        center[1] = -Math::GetRational(1, 2) * coeff.at(2);
        center[2] = -Math::GetRational(1, 2) * coeff.at(3);
        radius = Math::Sqrt(Math::FAbs(center.GetX() * center.GetX() + center.GetY() * center.GetY() + center.GetZ() * center.GetZ() - coeff.at(0)));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
    // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
    eigenValue = Math::FAbs(eigenSystem.GetEigenvalue(0));
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuadraticSphereFit3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) < radius && Math::GetValue(0) <= eigenValue)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::QuadraticSphereFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Real Mathematics::QuadraticSphereFit3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
Real Mathematics::QuadraticSphereFit3<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return eigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_SPHERE_FIT3_ACHIEVE_H
