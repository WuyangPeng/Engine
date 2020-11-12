///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 21:04)

// 3D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector3D.h"
#include "Vector3DOrthonormalBasisDetail.h"
#include "Vector3DOrthonormalizeDetail.h"
#include "Vector3DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
bool Mathematics::Vector3DTools<Real>::Approximate(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           Math::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::VectorMagnitude(const Vector3D& vector) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::VectorMagnitudeSquared(const Vector3D& vector) noexcept
{
    return vector.GetX() * vector.GetX() + vector.GetY() * vector.GetY() + vector.GetZ() * vector.GetZ();
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::DotProduct(const Vector3D& lhs, const Vector3D& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ());
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D
    Mathematics::Vector3DTools<Real>::CrossProduct(const Vector3D& lhs, const Vector3D& rhs) noexcept
{
    return Vector3D{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                     lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                     lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::CrossProductWithReduceMultiplication(const Vector3D& lhs, const Vector3D& rhs) noexcept
{
    auto t1 = lhs.GetX() - lhs.GetY();
    auto t2 = rhs.GetY() + rhs.GetZ();
    auto t3 = lhs.GetX() * rhs.GetZ();
    auto t4 = t1 * t2 - t3;

    return Vector3D{ rhs.GetY() * (t1 - lhs.GetZ()) - t4,
                     lhs.GetZ() * rhs.GetX() - t3,
                     t4 - lhs.GetY() * (rhs.GetX() - t2) };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::UnitCrossProduct(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    auto cross = CrossProduct(lhs, rhs);
    cross.Normalize(epsilon);

    return cross;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::Distance(const Vector3D& lhs, const Vector3D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::DistanceSquared(const Vector3D& lhs, const Vector3D& rhs) noexcept
{
    auto distanceX = lhs.GetX() - rhs.GetX();
    auto distanceY = lhs.GetY() - rhs.GetY();
    auto distanceZ = lhs.GetZ() - rhs.GetZ();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::ParallelVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)
{
    auto moduleSquare = VectorMagnitudeSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector3D();
    }
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::ApeakVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::ReflectionVector(const Vector3D& ray, const Vector3D& normal)
{
    return 2 * DotProduct(normal, ray) * normal - ray;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::RefractionVector(const Vector3D& ray, const Vector3D& normal, Real consistencyRatio)
{
    MATHEMATICS_ASSERTION_1(consistencyRatio <= 1, "consistencyRatio必须小于或等于1！");

    auto cosphi = DotProduct(-ray, normal);
    auto conphiSquare = cosphi * cosphi;
    auto consistencyRatioSquare = consistencyRatio * consistencyRatio;
    auto costheta = 1 / consistencyRatioSquare * Math::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

    return consistencyRatio * ray - (costheta + consistencyRatio * cosphi) * normal;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::FeatheringOutZAxes(const Vector3D& vector, Function function)
{
    if (function != nullptr)
    {
        auto r = function(vector.GetZ());

        return Vector3D{ vector.GetX() * r, vector.GetY() * r, vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s));
    }
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::TwistZAxes(const Vector3D& vector, Function function)
{
    if (function != nullptr)
    {
        auto delta = function(vector.GetZ());

        return Vector3D{ vector.GetX() * Math::Cos(delta) - vector.GetY() * Math::Sin(delta),
                         vector.GetX() * Math::Sin(delta) - vector.GetY() * Math::Cos(delta),
                         vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s));
    }
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>::BendYAxes(const Vector3D& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(bendAreaMin <= bendAreaMax, "bendAreaMin值必须小于或等于bendAreaMax！");

    auto y = vector.GetY();

    if (vector.GetY() <= bendAreaMin)
        y = bendAreaMin;
    else if (vector.GetY() >= bendAreaMax)
        y = bendAreaMax;

    auto delta = 1 / curvatureRadius * (y - bendCenter);

    Vector3D bendVector{};

    bendVector.SetX(vector.GetX());

    if (bendAreaMin <= vector.GetY() && vector.GetY() <= bendAreaMax)
    {
        bendVector.SetY(-Math::Sin(delta) * (vector.GetZ() - curvatureRadius) + bendCenter);
        bendVector.SetZ(-Math::Cos(delta) * (vector.GetZ() - curvatureRadius) + bendCenter);
    }
    else if (vector.GetY() < bendAreaMin)
    {
        bendVector.SetY(-Math::Sin(delta) * (vector.GetZ() - curvatureRadius) + bendCenter + Math::Cos(delta) * (vector.GetY() - bendAreaMin));

        bendVector.SetZ(-Math::Cos(delta) * (vector.GetZ() - curvatureRadius) + bendCenter + Math::Sin(delta) * (vector.GetY() - bendAreaMin));
    }
    else if (bendAreaMax < vector.GetY())
    {
        bendVector.SetY(-Math::Sin(delta) * (vector.GetZ() - curvatureRadius) + curvatureRadius + Math::Cos(delta) * (vector.GetY() - bendAreaMax));

        bendVector.SetZ(-Math::Cos(delta) * (vector.GetZ() - curvatureRadius) + curvatureRadius + Math::Sin(delta) * (vector.GetY() - bendAreaMax));
    }

    return bendVector;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::ScalarTripleProduct(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs) noexcept
{
    return DotProduct(CrossProduct(lhs, mhs), rhs);
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>::GetVectorIncludedAngle(const Vector3D& lhs, const Vector3D& rhs) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::AxesAlignBoundingBox3D Mathematics::Vector3DTools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    auto min = vectors.at(0);
    auto max = min;

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector3D::sm_PointSize; ++i)
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

    return AxesAlignBoundingBox3D{ min, max };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalize Mathematics::Vector3DTools<Real>::Orthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon)
{
    // 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) /
    //        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    //
    // 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector3DOrthonormalize{ lhs, mhs, rhs, epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalize Mathematics::Vector3DTools<Real>::Orthonormalize(const ContainerType& vectors, const Real epsilon)
{
    MATHEMATICS_ASSERTION_0(vectors.size() == 3, "vectors的大小错误！");

    return Vector3DOrthonormalize{ vectors, epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalBasis Mathematics::Vector3DTools<Real>::GenerateOrthonormalBasis(const Vector3D& nonzeroVector, const Real epsilon)
{
    MATHEMATICS_ASSERTION_0(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    return Vector3DOrthonormalBasis{ nonzeroVector, false, epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalBasis Mathematics::Vector3DTools<Real>::GenerateComplementBasis(const Vector3D& unitVector, const Real epsilon)
{
    MATHEMATICS_ASSERTION_0(unitVector.IsNormalize(epsilon), "输入必须是单位向量！");

    return Vector3DOrthonormalBasis{ unitVector, true, epsilon };
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_ACHIEVE_H
