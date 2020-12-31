///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 15:09)

// 2D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector2D.h"
#include "Vector2DOrthonormalBasisDetail.h"
#include "Vector2DOrthonormalizeDetail.h"
#include "Vector2DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
bool Mathematics::Vector2DTools<Real>::Approximate(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon && Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::VectorMagnitude(const Vector2D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::VectorMagnitudeSquared(const Vector2D& vector) noexcept
{
    return vector.GetX() * vector.GetX() + vector.GetY() * vector.GetY();
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::Distance(const Vector2D& lhs, const Vector2D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::DistanceSquared(const Vector2D& lhs, const Vector2D& rhs) noexcept
{
    auto distanceX = lhs.GetX() - rhs.GetX();
    auto distanceY = lhs.GetY() - rhs.GetY();

    return distanceX * distanceX + distanceY * distanceY;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::DotProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY());
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::PseudoCrossProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept
{
    return DotPerp(lhs, rhs);
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>::ParallelVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    auto moduleSquare = VectorMagnitudeSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector2D{};
    }
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>::ApeakVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::GetVectorIncludedAngle(const Vector2D& lhs, const Vector2D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>::GetPerp(const Vector2D& vector) noexcept
{
    return Vector2D{ vector.GetY(), -vector.GetX() };
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>::GetUnitPerp(const Vector2D& vector, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    auto perp = GetPerp(vector);
    perp.Normalize(epsilon);

    return perp;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>::DotPerp(const Vector2D& lhs, const Vector2D& rhs) noexcept
{
    return DotProduct(Vector2D(-lhs.GetY(), lhs.GetX()), rhs);
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::AxesAlignBoundingBox2D Mathematics::Vector2DTools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    auto min = vectors.at(0);
    auto max = min;

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector2D::sm_PointSize; ++i)
        {
            if (eachVector[i] < min[i])
            {
                min[i] = eachVector[i];
            }
            else if (max[i] < eachVector[i])
            {
                max[i] = eachVector[i];
            }
        }
    }

    return AxesAlignBoundingBox2D{ min, max };
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::Vector2DOrthonormalize Mathematics::Vector2DTools<Real>::Orthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
    // 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
    //
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //
    // 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector2DOrthonormalize{ lhs, rhs, epsilon };
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::Vector2DOrthonormalBasis Mathematics::Vector2DTools<Real>::GenerateOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    return Vector2DOrthonormalBasis{ nonzeroVector, epsilon };
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_ACHIEVE_H