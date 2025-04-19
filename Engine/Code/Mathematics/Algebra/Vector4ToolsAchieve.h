///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:18)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H

#include "AxesAlignBoundingBox4Detail.h"
#include "Vector3Detail.h"
#include "Vector4Detail.h"
#include "Vector4Tools.h"

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector4Tools<Real>::Approximate(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return MathType::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           MathType::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           MathType::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon &&
           MathType::FAbs(lhs.GetW() - rhs.GetW()) < epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::GetRobustLength(const Vector4Type& vector)
{
    const auto maxAbsComp = vector.GetMaxAbsComp();

    if (MathType::GetZeroTolerance() < maxAbsComp)
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::GetLength(const Vector4Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::GetLengthSquared(const Vector4Type& vector) noexcept
{
    return vector.GetX() * vector.GetX() +
           vector.GetY() * vector.GetY() +
           vector.GetZ() * vector.GetZ() +
           vector.GetW() * vector.GetW();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::Distance(const Vector4Type& lhs, const Vector4Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::DistanceSquared(const Vector4Type& lhs, const Vector4Type& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();
    const auto distanceZ = lhs.GetZ() - rhs.GetZ();
    const auto distanceW = lhs.GetW() - rhs.GetW();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ + distanceW * distanceW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::DotProduct(const Vector4Type& lhs, const Vector4Type& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() +
            lhs.GetY() * rhs.GetY() +
            lhs.GetZ() * rhs.GetZ() +
            lhs.GetW() * rhs.GetW());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4Tools<Real>::Vector4Type Mathematics::Vector4Tools<Real>::ParallelVectorLhsToRhs(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon)
{
    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector4Type{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4Tools<Real>::Vector4Type Mathematics::Vector4Tools<Real>::ApeakVectorLhsToRhs(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::GetVectorIncludedAngle(const Vector4Type& lhs, const Vector4Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4Tools<Real>::AxesAlignBoundingBox4D Mathematics::Vector4Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector4Type min{ MathType::maxReal, MathType::maxReal, MathType::maxReal, MathType::maxReal };
    Vector4Type max{ MathType::minReal, MathType::minReal, MathType::minReal, MathType::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector4Type::pointSize; ++i)
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
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector4Tools<Real>::ProjectHomogeneous(const Vector4Type& vector) noexcept
{
    return Vector3Type{ vector.GetX(), vector.GetY(), vector.GetZ() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector4Tools<Real>::Project(const Vector4Type& vector, int reject)
{
    Vector3Type result{};

    auto i = 0;
    auto j = 0;
    while (i < Vector3Type::pointSize)
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
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector4Tools<Real>::HyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2)
{
    const auto m01 = v0[0] * v1[1] - v0[1] * v1[0];  // x0 * y1 - y0 * x1
    const auto m02 = v0[0] * v1[2] - v0[2] * v1[0];  // x0 * z1 - z0 * x1
    const auto m03 = v0[0] * v1[3] - v0[3] * v1[0];  // x0 * w1 - w0 * x1
    const auto m12 = v0[1] * v1[2] - v0[2] * v1[1];  // y0 * z1 - z0 * y1
    const auto m13 = v0[1] * v1[3] - v0[3] * v1[1];  // y0 * w1 - w0 * y1
    const auto m23 = v0[2] * v1[3] - v0[3] * v1[2];  // z0 * w1 - w0 * z1

    return Vector4Type{
        +m23 * v2[1] - m13 * v2[2] + m12 * v2[3],  // +m23 * y2 - m13 * z2 + m12 * w2
        -m23 * v2[0] + m03 * v2[2] - m02 * v2[3],  // -m23 * x2 + m03 * z2 - m02 * w2
        +m13 * v2[0] - m03 * v2[1] + m01 * v2[3],  // +m13 * x2 - m03 * y2 + m01 * w2
        -m12 * v2[0] + m02 * v2[1] - m01 * v2[2]  // -m12 * x2 + m02 * y2 - m01 * z2
    };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector4Tools<Real>::UnitHyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2, bool robust, const Real epsilon)
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::DotHyperCross(const Vector4Type& v0, const Vector4Type& v1, const Vector4Type& v2, const Vector4Type& v3)
{
    return DotProduct(HyperCross(v0, v1, v2), v3);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::ComputeOrthogonalComplement(const ContainerType& container, bool robust, Real epsilon)
{
    auto vector = container;
    if (vector.size() == 1u)
    {
        const auto& v0 = vector.at(0);

        auto maxIndex = 0;
        auto maxAbsValue = MathType::FAbs(v0[0]);
        for (auto i = 1; i < Vector4Type::pointSize; ++i)
        {
            auto absValue = MathType::FAbs(v0[i]);
            if (maxAbsValue < absValue)
            {
                maxIndex = i;
                maxAbsValue = absValue;
            }
        }

        if (maxIndex < 2)
        {
            vector.emplace_back(-v0[1], +v0[0], MathType::GetValue(0), MathType::GetValue(0));
        }
        else if (maxIndex == 3)
        {
            vector.emplace_back(MathType::GetValue(0), +v0[2], -v0[0], MathType::GetValue(0));
        }
        else
        {
            vector.emplace_back(MathType::GetValue(0), MathType::GetValue(0), -v0[3], +v0[2]);
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

        auto maxIndex = 0u;
        auto maxAbsValue = MathType::FAbs(det.at(0));
        for (auto i = 1u; i < det.size(); ++i)
        {
            auto absValue = MathType::FAbs(det.at(i));
            if (maxAbsValue < absValue)
            {
                maxIndex = i;
                maxAbsValue = absValue;
            }
        }

        if (maxIndex == 0)
        {
            vector.emplace_back(-det.at(4), +det.at(2), MathType::GetValue(0), -det.at(0));
        }
        else if (maxIndex <= 2)
        {
            vector.emplace_back(+det.at(5), MathType::GetValue(0), -det.at(2), +det.at(1));
        }
        else
        {
            vector.emplace_back(MathType::GetValue(0), -det.at(5), +det.at(4), -det.at(3));
        }
    }

    if (vector.size() == 3u)
    {
        vector.emplace_back(HyperCross(vector.at(0), vector.at(1), vector.at(2)));

        return Orthonormalize(vector, robust, epsilon);
    }

    return MathType::GetValue(0);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4Tools<Real>::Orthonormalize(const ContainerType& container, bool robust, Real epsilon)
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

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4Tools<Real>::Vector4Type Mathematics::Vector4Tools<Real>::CrossProduct(const Vector4Type& lhs, const Vector4Type& rhs) noexcept
{
    return Vector4Type{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                    lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                    lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX(),
                    Real{} };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4Tools<Real>::Vector4Type Mathematics::Vector4Tools<Real>::UnitCrossProduct(const Vector4Type& lhs, const Vector4Type& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    auto cross = CrossProduct(lhs, rhs);
    cross.Normalize(epsilon);

    return cross;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_TOOLS_ACHIEVE_H
