///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/03 14:43)

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
bool Mathematics::Vector2Tools<Real>::Approximate(const Vector2& lhs, const Vector2& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon && Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::GetLength(const Vector2& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::GetRobustLength(const Vector2& vector) 
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
Real Mathematics::Vector2Tools<Real>::GetLengthSquared(const Vector2& vector) noexcept
{
    return DotProduct(vector, vector);
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::Distance(const Vector2& lhs, const Vector2& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::DistanceSquared(const Vector2& lhs, const Vector2& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();

    return distanceX * distanceX + distanceY * distanceY;
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::DotProduct(const Vector2& lhs, const Vector2& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY());
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::PseudoCrossProduct(const Vector2& lhs, const Vector2& rhs) noexcept
{
    return DotPerp(lhs, rhs);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::ParallelVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, const Real epsilon)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector2{};
    }
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::ApeakVectorLhsToRhs(const Vector2& lhs, const Vector2& rhs, const Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::GetVectorIncludedAngle(const Vector2& lhs, const Vector2& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::GetPerp(const Vector2& vector) noexcept
{
    return Vector2{ vector.GetY(), -vector.GetX() };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2Tools<Real>::GetUnitPerp(const Vector2& vector, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    auto perp = GetPerp(vector);
    perp.Normalize(epsilon);

    return perp;
}

template <typename Real>
Real Mathematics::Vector2Tools<Real>::DotPerp(const Vector2& lhs, const Vector2& rhs) noexcept
{
    return DotProduct(Vector2(-lhs.GetY(), lhs.GetX()), rhs);
}

template <typename Real>
typename Mathematics::Vector2Tools<Real>::AxesAlignBoundingBox2 Mathematics::Vector2Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector2 min{ Math::maxReal, Math::maxReal };
    Vector2 max{ Math::minReal, Math::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector2::pointSize; ++i)
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

    return AxesAlignBoundingBox2{ min, max };
}

template <typename Real>
typename Mathematics::Vector2Tools<Real>::Vector2Orthonormalize Mathematics::Vector2Tools<Real>::Orthonormalize(const Vector2& lhs, const Vector2& rhs, const Real epsilon)
{
    /// 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
    ///
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector2Orthonormalize{ lhs, rhs, epsilon };
}

template <typename Real>
typename Mathematics::Vector2Tools<Real>::Vector2OrthonormalBasis Mathematics::Vector2Tools<Real>::GenerateOrthonormalBasis(const Vector2& nonzeroVector, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    return Vector2OrthonormalBasis{ nonzeroVector, epsilon };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector2Tools<Real>::LiftHomogeneous(const Vector2& vector, Real last) noexcept
{
    return Vector3{ vector.GetX(), vector.GetY(), last };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector2Tools<Real>::Lift(const Vector2& vector, int inject, Real value)
{
    Vector3 result{};

    auto i = 0;
    for (; i < inject && i < Vector2::pointSize; ++i)
    {
        result[i] = vector[i];
    }
    result[i] = value;

    for (; i < Vector3::pointSize; ++i)
    {
        result[i + 1] = vector[i];
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_ACHIEVE_H