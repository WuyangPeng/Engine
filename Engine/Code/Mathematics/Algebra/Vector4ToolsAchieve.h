///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/03 14:42)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H

#include "AxesAlignBoundingBox4Detail.h"
#include "Vector3Detail.h"
#include "Vector4Detail.h"
#include "Vector4Tools.h"

template <typename Real>
bool Mathematics::Vector4Tools<Real>::Approximate(const Vector4& lhs, const Vector4& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           Math::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon &&
           Math::FAbs(lhs.GetW() - rhs.GetW()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::GetRobustLength(const Vector4& vector)
{
    const auto maxAbsComp = vector.GetMaxAbsComp();

    if (Math::GetZeroTolerance() < maxAbsComp)
    {
        const auto scaled = vector / maxAbsComp;
        return maxAbsComp * GetLength(scaled);
    }
    else
    {
        return GetLength(vector);
    }
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::GetLength(const Vector4& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::GetLengthSquared(const Vector4& vector) noexcept
{
    return vector.GetX() * vector.GetX() +
           vector.GetY() * vector.GetY() +
           vector.GetZ() * vector.GetZ() +
           vector.GetW() * vector.GetW();
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::Distance(const Vector4& lhs, const Vector4& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::DistanceSquared(const Vector4& lhs, const Vector4& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();
    const auto distanceZ = lhs.GetZ() - rhs.GetZ();
    const auto distanceW = lhs.GetW() - rhs.GetW();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ + distanceW * distanceW;
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::DotProduct(const Vector4& lhs, const Vector4& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() +
            lhs.GetY() * rhs.GetY() +
            lhs.GetZ() * rhs.GetZ() +
            lhs.GetW() * rhs.GetW());
}

template <typename Real>
typename Mathematics::Vector4Tools<Real>::Vector4 Mathematics::Vector4Tools<Real>::ParallelVectorLhsToRhs(const Vector4& lhs, const Vector4& rhs, const Real epsilon)
{
    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector4();
    }
}

template <typename Real>
typename Mathematics::Vector4Tools<Real>::Vector4 Mathematics::Vector4Tools<Real>::ApeakVectorLhsToRhs(const Vector4& lhs, const Vector4& rhs, const Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::GetVectorIncludedAngle(const Vector4& lhs, const Vector4& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
typename Mathematics::Vector4Tools<Real>::AxesAlignBoundingBox4D Mathematics::Vector4Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector4 min{ Math::maxReal, Math::maxReal, Math::maxReal, Math::maxReal };
    Vector4 max{ Math::minReal, Math::minReal, Math::minReal, Math::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector4::pointSize; ++i)
        {
            if (eachVector[i] < min[i])
            {
                min[i] = eachVector[i];
            }

            if (max[i] < eachVector[i])
            {
                max[i] = eachVector[i];
            }
        }
    }

    return AxesAlignBoundingBox4D{ min, max };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector4Tools<Real>::ProjectHomogeneous(const Vector4& vector) noexcept
{
    return Vector3{ vector.GetX(), vector.GetY(), vector.GetZ() };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector4Tools<Real>::Project(const Vector4& vector, int reject)
{
    Vector3 result{};

    auto i = 0;
    auto j = 0;
    while (i < Vector3::pointSize)
    {
        if (j == reject)
        {
            ++j;
        }

        result[i] = vector[j];

        ++i;
        ++j;
    }

    return result;
}

template <typename Real>
Mathematics::Vector4<Real> Mathematics::Vector4Tools<Real>::HyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2)
{
    Real m01 = v0[0] * v1[1] - v0[1] * v1[0];  // x0 * y1 - y0 * x1
    Real m02 = v0[0] * v1[2] - v0[2] * v1[0];  // x0 * z1 - z0 * x1
    Real m03 = v0[0] * v1[3] - v0[3] * v1[0];  // x0 * w1 - w0 * x1
    Real m12 = v0[1] * v1[2] - v0[2] * v1[1];  // y0 * z1 - z0 * y1
    Real m13 = v0[1] * v1[3] - v0[3] * v1[1];  // y0 * w1 - w0 * y1
    Real m23 = v0[2] * v1[3] - v0[3] * v1[2];  // z0 * w1 - w0 * z1

    return Vector4{
        +m23 * v2[1] - m13 * v2[2] + m12 * v2[3],  // +m23 * y2 - m13 * z2 + m12 * w2
        -m23 * v2[0] + m03 * v2[2] - m02 * v2[3],  // -m23 * x2 + m03 * z2 - m02 * w2
        +m13 * v2[0] - m03 * v2[1] + m01 * v2[3],  // +m13 * x2 - m03 * y2 + m01 * w2
        -m12 * v2[0] + m02 * v2[1] - m01 * v2[2]  // -m12 * x2 + m02 * y2 - m01 * z2
    };
}

template <typename Real>
Mathematics::Vector4<Real> Mathematics::Vector4Tools<Real>::UnitHyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2, bool robust, const Real epsilon)
{
    auto unitHyperCross = HyperCross(v0, v1, v2);

    if (robust)
    {
        unitHyperCross.RobustNormalize(epsilon);
    }
    else
    {
        unitHyperCross.Normalize(epsilon);
    }

    return unitHyperCross;
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::DotHyperCross(const Vector4& v0, const Vector4& v1, const Vector4& v2, const Vector4& v3)
{
    return DotProduct(HyperCross(v0, v1, v2), v3);
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::ComputeOrthogonalComplement(const ContainerType& container, bool robust, const Real epsilon)
{
    auto vector = container;
    if (vector.size() == 1u)
    {
        const auto& v0 = vector.at(0);

        auto maxIndex = 0;
        auto maxAbsValue = Math::FAbs(v0[0]);
        for (auto i = 1; i < Vector4::pointSize; ++i)
        {
            auto absValue = Math::FAbs(v0[i]);
            if (maxAbsValue < absValue)
            {
                maxIndex = i;
                maxAbsValue = absValue;
            }
        }

        if (maxIndex < 2)
        {
            vector.emplace_back(-v0[1], +v0[0], Math::GetValue(0), Math::GetValue(0));
        }
        else if (maxIndex == 3)
        {
            vector.emplace_back(Math::GetValue(0), +v0[2], -v0[0], Math::GetValue(0));
        }
        else
        {
            vector.emplace_back(Math::GetValue(0), Math::GetValue(0), -v0[3], +v0[2]);
        }
    }

    if (vector.size() == 2u)
    {
        const auto& v0 = vector.at(0);
        const auto& v1 = vector.at(1);

        std::array<Real, 6> det{ v0[0] * v1[1] - v1[0] * v0[1],
                                 v0[0] * v1[2] - v1[0] * v0[2],
                                 v0[0] * v1[3] - v1[0] * v0[3],
                                 v0[1] * v1[2] - v1[1] * v0[2],
                                 v0[1] * v1[3] - v1[1] * v0[3],
                                 v0[2] * v1[3] - v1[2] * v0[3] };

        auto maxIndex = 0;
        auto maxAbsValue = Math::FAbs(det.at(0));
        for (auto i = 1u; i < det.size(); ++i)
        {
            auto absValue = Math::FAbs(det.at(i));
            if (maxAbsValue < absValue)
            {
                maxIndex = i;
                maxAbsValue = absValue;
            }
        }

        if (maxIndex == 0)
        {
            vector.emplace_back(-det.at(4), +det.at(2), Math::GetValue(0), -det.at(0));
        }
        else if (maxIndex <= 2)
        {
            vector.emplace_back(+det.at(5), Math::GetValue(0), -det.at(2), +det.at(1));
        }
        else
        {
            vector.emplace_back(Math::GetValue(0), -det.at(5), +det.at(4), -det.at(3));
        }
    }

    if (vector.size() == 3u)
    {
        vector.emplace_back(HyperCross(vector.at(0), vector.at(1), vector.at(2)));

        return Orthonormalize(vector, robust, epsilon);
    }

    return Math::GetValue(0);
}

template <typename Real>
Real Mathematics::Vector4Tools<Real>::Orthonormalize(const ContainerType& container, bool robust, const Real epsilon)
{
    auto vector = container;
    auto& v0 = vector.at(0);
    auto minLength = robust ? GetRobustLength(v0) : GetLength(v0);

    if (robust)
    {
        v0.RobustNormalize(epsilon);
    }
    else
    {
        v0.Normalize(epsilon);
    }

    for (auto i = 1u; i < vector.size(); ++i)
    {
        auto& vi = vector.at(i);

        for (auto j = 0u; j < i; ++j)
        {
            const auto& vj = vector.at(j);
            const auto dot = DotProduct(vi, vj);
            vi -= vj * dot;
        }
        auto length = robust ? GetRobustLength(vi) : GetLength(vi);

        if (robust)
        {
            vi.RobustNormalize(epsilon);
        }
        else
        {
            vi.Normalize(epsilon);
        }

        if (length < minLength)
        {
            minLength = length;
        }
    }

    return minLength;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H
