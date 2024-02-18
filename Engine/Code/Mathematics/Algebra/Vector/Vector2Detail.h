///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 09:50)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_DETAIL_H

#include "Vector2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector2<Real> Mathematics::Algebra::Perp(const Vector2<Real>& vector)
{
    return Vector2<Real>{ vector[1], -vector[0] };
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector2<Real> Mathematics::Algebra::UnitPerp(const Vector2<Real>& vector, bool robust)
{
    Vector2<Real> unitPerp{ vector[1], -vector[0] };

    Normalize(unitPerp, robust);

    return unitPerp;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::DotPerp(const Vector2<Real>& lhs, const Vector2<Real>& rhs)
{
    return Dot(lhs, Perp(rhs));
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::ComputeOrthogonalComplement(int numInputs, std::vector<Vector2<Real>>& vector, bool robust)
{
    if (numInputs == 1)
    {
        vector[1] = -Perp(vector[0]);

        return Orthonormalize<2, Real>(2, vector, robust);
    }

    return Real{};
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::ComputeBarycentric(const Vector2<Real>& point, const Vector2<Real>& v0, const Vector2<Real>& v1, const Vector2<Real>& v2, std::array<Real, 3>& bary, Real epsilon)
{
    // 计算相对于三角形的V2的矢量。
    std::array<Vector2<Real>, 3> diff{ v0 - v2, v1 - v2, point - v2 };

    const auto det = DotPerp(diff.at(0), diff.at(1));
    if (det < -epsilon || epsilon < det)
    {
        bary.at(0) = DotPerp(diff.at(2), diff.at(1)) / det;
        bary.at(1) = DotPerp(diff.at(0), diff.at(2)) / det;
        bary.at(2) = Math<Real>::GetValue(1) - bary.at(0) - bary.at(1);

        return true;
    }

    bary.fill(Real{});

    return false;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_DETAIL_H
