///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_ACHIEVE_H

#include "AxesAlignBoundingBox2Detail.h"
#include "BarycentricCoordinatesDetail.h"
#include "Vector2Detail.h"
#include "Vector2OrthonormalBasisDetail.h"
#include "Vector2OrthonormalizeDetail.h"
#include "Vector2Tools.h"
#include "Vector3Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2Tools<Real>::Approximate(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return MathType::FAbs(lhs.GetX() - rhs.GetX()) < epsilon && MathType::FAbs(lhs.GetY() - rhs.GetY()) < epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::GetLength(const Vector2Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::GetRobustLength(const Vector2Type& vector)
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
Real Mathematics::Vector2Tools<Real>::GetLengthSquared(const Vector2Type& vector) noexcept
{
    return DotProduct(vector, vector);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::Distance(const Vector2Type& lhs, const Vector2Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::DistanceSquared(const Vector2Type& lhs, const Vector2Type& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();

    return distanceX * distanceX + distanceY * distanceY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::DotProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::PseudoCrossProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept
{
    return DotPerp(lhs, rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::ParallelVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon)
{
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector2Type{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::ApeakVectorLhsToRhs(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::GetVectorIncludedAngle(const Vector2Type& lhs, const Vector2Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::GetPerp(const Vector2Type& vector) noexcept
{
    return Vector2Type{ vector.GetY(), -vector.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::GetUnitPerp(const Vector2Type& vector, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    auto perp = GetPerp(vector);
    perp.Normalize(epsilon);

    return perp;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Tools<Real>::DotPerp(const Vector2Type& lhs, const Vector2Type& rhs) noexcept
{
    return DotProduct(Vector2Type(-lhs.GetY(), lhs.GetX()), rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Tools<Real>::AxesAlignBoundingBox2Type Mathematics::Vector2Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector2Type min{ MathType::maxReal, MathType::maxReal };
    Vector2Type max{ MathType::minReal, MathType::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector2Type::pointSize; ++i)
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

    return AxesAlignBoundingBox2Type{ min, max };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Tools<Real>::Vector2OrthonormalizeType Mathematics::Vector2Tools<Real>::Orthonormalize(const Vector2Type& lhs, const Vector2Type& rhs, Real epsilon)
{
    /// 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
    ///
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector2OrthonormalizeType{ lhs, rhs, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Tools<Real>::Vector2OrthonormalBasisType Mathematics::Vector2Tools<Real>::GenerateOrthonormalBasis(const Vector2Type& nonzeroVector, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector2OrthonormalBasisType{ nonzeroVector, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector2Tools<Real>::LiftHomogeneous(const Vector2Type& vector, Real last) noexcept
{
    return Vector3Type{ vector.GetX(), vector.GetY(), last };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector2Tools<Real>::Lift(const Vector2Type& vector, int inject, Real value)
{
    Vector3Type result{};

    auto i = 0;
    for (; i < inject && i < Vector2Type::pointSize; ++i)
    {
        result[i] = vector[i];
    }
    result[i] = value;

    for (; i < Vector3Type::pointSize; ++i)
    {
        result[i + 1] = vector[i];
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_ACHIEVE_H