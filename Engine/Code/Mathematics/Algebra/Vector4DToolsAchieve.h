///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 16:02)

// 4D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_ACHIEVE_H

#include "Vector4D.h"
#include "Vector4DTools.h"

template <typename Real>
bool Mathematics::Vector4DTools<Real>::Approximate(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           Math::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon &&
           Math::FAbs(lhs.GetW() - rhs.GetW()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::VectorMagnitude(const Vector4D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::VectorMagnitudeSquared(const Vector4D& vector) noexcept
{
    return vector.GetX() * vector.GetX() +
           vector.GetY() * vector.GetY() +
           vector.GetZ() * vector.GetZ() +
           vector.GetW() * vector.GetW();
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::Distance(const Vector4D& lhs, const Vector4D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::DistanceSquared(const Vector4D& lhs, const Vector4D& rhs) noexcept
{
    auto distanceX = lhs.GetX() - rhs.GetX();
    auto distanceY = lhs.GetY() - rhs.GetY();
    auto distanceZ = lhs.GetZ() - rhs.GetZ();
    auto distanceW = lhs.GetW() - rhs.GetW();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ + distanceW * distanceW;
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::DotProduct(const Vector4D& lhs, const Vector4D& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() +
            lhs.GetY() * rhs.GetY() +
            lhs.GetZ() * rhs.GetZ() +
            lhs.GetW() * rhs.GetW());
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::Vector4D Mathematics::Vector4DTools<Real>::ParallelVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon)
{
    auto moduleSquare = VectorMagnitudeSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector4D();
    }
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::Vector4D Mathematics::Vector4DTools<Real>::ApeakVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>::GetVectorIncludedAngle(const Vector4D& lhs, const Vector4D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::AxesAlignBoundingBox4D Mathematics::Vector4DTools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    auto min = vectors.at(0);
    auto max = min;

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector4D::sm_PointSize; ++i)
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

    return AxesAlignBoundingBox4D{ min, max };
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_ACHIEVE_H
