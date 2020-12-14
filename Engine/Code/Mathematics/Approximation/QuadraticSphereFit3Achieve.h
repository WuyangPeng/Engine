///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 11:13)

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
    : m_Center{}, m_Radius{}, m_EigenValue{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticSphereFit3<Real>::Calculate(const Points& points)
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
        auto r2 = x2 + y2 + z2;
        auto xr2 = x * r2;
        auto yr2 = y * r2;
        auto zr2 = z * r2;
        auto r4 = r2 * r2;

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
    if (Math::GetZeroTolerance() < Math::FAbs(eigenVector[4]))
    {
        Real inv = Math::GetValue(1) / eigenVector[4];

        std::array<Real, 4> coeff{ inv * eigenVector[0], inv * eigenVector[1], inv * eigenVector[2], inv * eigenVector[3] };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Center[0] = -Math::GetRational(1, 2) * coeff[1];
        m_Center[1] = -Math::GetRational(1, 2) * coeff[2];
        m_Center[2] = -Math::GetRational(1, 2) * coeff[3];
        m_Radius = Math::Sqrt(Math::FAbs(m_Center.GetX() * m_Center.GetX() + m_Center.GetY() * m_Center.GetY() + m_Center.GetZ() * m_Center.GetZ() - coeff[0]));

#include STSTEM_WARNING_POP
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
    // 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
    m_EigenValue = Math::FAbs(eigenSystem.GetEigenvalue(0));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuadraticSphereFit3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) < m_Radius && Math::GetValue(0) <= m_EigenValue)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::QuadraticSphereFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
Real Mathematics::QuadraticSphereFit3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
Real Mathematics::QuadraticSphereFit3<Real>::GetEigenValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_EigenValue;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_SPHERE_FIT3_ACHIEVE_H
