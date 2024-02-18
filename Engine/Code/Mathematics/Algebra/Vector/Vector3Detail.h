///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 11:34)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_DETAIL_H

#include "Vector3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Cross(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{};

    result[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
    result[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
    result[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];

    return result;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::UnitCross(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs, bool robust)
{
    auto unitCross = Cross(lhs, rhs);

    Normalize(unitCross, robust);

    return unitCross;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::DotCross(const Vector<N, Real>& v0, const Vector<N, Real>& v1, const Vector<N, Real>& v2)
{
    return Dot(v0, Cross(v1, v2));
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::ComputeOrthogonalComplement(int numInputs, std::vector<Vector3<Real>>& vector, bool robust)
{
    if (numInputs == 1)
    {
        if (Math<Real>::FAbs(vector.at(0)[1]) < Math<Real>::FAbs(vector.at(0)[0]))
        {
            vector.at(1) = { -vector.at(0)[2], Real{}, +vector.at(0)[0] };
        }
        else
        {
            vector.at(1) = { Real{}, +vector.at(0)[2], -vector.at(0)[1] };
        }
        numInputs = 2;
    }

    if (numInputs == 2)
    {
        vector.at(2) = Cross(vector.at(0), vector.at(1));

        return Orthonormalize<3, Real>(3, vector, robust);
    }

    return Real{};
}

template <typename Real>
void Mathematics::Algebra::FastComputeOrthogonalComplement(const Vector3<Real>& v2, Vector3<Real>& v0, Vector3<Real>& v1)
{
    if (Real{} <= v2[2])
    {
        const auto value0 = Math<Real>::GetValue(1) + v2[2];
        const auto value1 = -v2[0] * v2[1] / value0;
        const auto value2 = v2[1] * v2[1] / value0;
        v0 = { v2[2] + value2, value1, -v2[0] };
        v1 = { value1, Math<Real>::GetValue(1) - value2, -v2[1] };
    }
    else
    {
        const auto value0 = Math<Real>::GetValue(1) - v2[2];
        const auto value1 = v2[0] * v2[1] / value0;
        const auto value2 = v2[1] * v2[1] / value0;
        v0 = { -v2[2] + value2, -value1, v2[0] };
        v1 = { value1, -Math<Real>::GetValue(1) + value2, -v2[1] };
    }
}

template <typename Real>
bool Mathematics::Algebra::ComputeBarycentric(const Vector3<Real>& point, const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, std::array<Real, 4>& bary, Real epsilon)
{
    /// 计算相对于四面体的V3的矢量。
    std::array<Vector3<Real>, 4> diff = { v0 - v3, v1 - v3, v2 - v3, point - v3 };

    const auto det = DotCross(diff.at(0), diff.at(1), diff.at(2));
    if (det < -epsilon || epsilon < det)
    {
        bary.at(0) = DotCross(diff.at(3), diff.at(1), diff.at(2)) / det;
        bary.at(1) = DotCross(diff.at(3), diff.at(2), diff.at(0)) / det;
        bary.at(2) = DotCross(diff.at(3), diff.at(0), diff.at(1)) / det;
        bary.at(3) = Math<Real>::GetValue(1) - bary.at(0) - bary.at(1) - bary.at(2);

        return true;
    }

    bary.fill(Real{});

    return false;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_DETAIL_H
