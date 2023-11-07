///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:17)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_ACHIEVE_H

#include "AxesAlignBoundingBox3Detail.h"
#include "BarycentricCoordinatesDetail.h"
#include "Vector2Detail.h"
#include "Vector3Detail.h"
#include "Vector3OrthonormalBasisDetail.h"
#include "Vector3OrthonormalizeDetail.h"
#include "Vector3Tools.h"
#include "Vector4Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Tools<Real>::Approximate(const Vector3& lhs, const Vector3& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return Math::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           Math::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           Math::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetRobustLength(const Vector3& vector)
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetLength(const Vector3& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return Math::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetLengthSquared(const Vector3& vector) noexcept
{
    return vector.GetX() * vector.GetX() + vector.GetY() * vector.GetY() + vector.GetZ() * vector.GetZ();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::DotProduct(const Vector3& lhs, const Vector3& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::CrossProduct(const Vector3& lhs, const Vector3& rhs) noexcept
{
    return Vector3{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                    lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                    lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::CrossProductWithReduceMultiplication(const Vector3& lhs, const Vector3& rhs) noexcept
{
    const auto t1 = lhs.GetX() - lhs.GetY();
    const auto t2 = rhs.GetY() + rhs.GetZ();
    const auto t3 = lhs.GetX() * rhs.GetZ();
    const auto t4 = t1 * t2 - t3;

    return Vector3{ rhs.GetY() * (t1 - lhs.GetZ()) - t4,
                    lhs.GetZ() * rhs.GetX() - t3,
                    t4 - lhs.GetY() * (rhs.GetX() - t2) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::UnitCrossProduct(const Vector3& lhs, const Vector3& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    auto cross = CrossProduct(lhs, rhs);
    cross.Normalize(epsilon);

    return cross;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::Distance(const Vector3& lhs, const Vector3& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::DistanceSquared(const Vector3& lhs, const Vector3& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();
    const auto distanceZ = lhs.GetZ() - rhs.GetZ();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::ParallelVectorLhsToRhs(const Vector3& lhs, const Vector3& rhs, Real epsilon)
{
    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector3();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::ApeakVectorLhsToRhs(const Vector3& lhs, const Vector3& rhs, Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::ReflectionVector(const Vector3& ray, const Vector3& normal)
{
    return 2 * DotProduct(normal, ray) * normal - ray;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::RefractionVector(const Vector3& ray, const Vector3& normal, Real consistencyRatio)
{
    MATHEMATICS_ASSERTION_1(consistencyRatio <= 1, "consistencyRatio必须小于或等于1！");

    const auto cosphi = DotProduct(-ray, normal);
    const auto conphiSquare = cosphi * cosphi;
    const auto consistencyRatioSquare = consistencyRatio * consistencyRatio;
    const auto costheta = 1 / consistencyRatioSquare * Math::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

    return consistencyRatio * ray - (costheta + consistencyRatio * cosphi) * normal;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::FeatheringOutZAxes(const Vector3& vector, Function function)
{
    if (function != nullptr)
    {
        const auto r = function(vector.GetZ());

        return Vector3{ vector.GetX() * r, vector.GetY() * r, vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::TwistZAxes(const Vector3& vector, Function function)
{
    if (function != nullptr)
    {
        const auto delta = function(vector.GetZ());

        return Vector3{ vector.GetX() * Math::Cos(delta) - vector.GetY() * Math::Sin(delta),
                        vector.GetX() * Math::Sin(delta) - vector.GetY() * Math::Cos(delta),
                        vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3 Mathematics::Vector3Tools<Real>::BendYAxes(const Vector3& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(bendAreaMin <= bendAreaMax, "bendAreaMin值必须小于或等于bendAreaMax！");

    auto y = vector.GetY();

    if (vector.GetY() <= bendAreaMin)
        y = bendAreaMin;
    else if (vector.GetY() >= bendAreaMax)
        y = bendAreaMax;

    const auto delta = 1 / curvatureRadius * (y - bendCenter);

    Vector3 bendVector{};

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
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::ScalarTripleProduct(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2) noexcept
{
    return DotProduct(CrossProduct(vector0, vector1), vector2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetVectorIncludedAngle(const Vector3& lhs, const Vector3& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return Math::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::AxesAlignBoundingBox3D Mathematics::Vector3Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector3 min{ Math::maxReal, Math::maxReal, Math::maxReal };
    Vector3 max{ Math::minReal, Math::minReal, Math::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector3::pointSize; ++i)
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

    return AxesAlignBoundingBox3D{ min, max };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Orthonormalize Mathematics::Vector3Tools<Real>::Orthonormalize(const Vector3& uVector, const Vector3& vVector, const Vector3& wVector, const Real epsilon)
{
    /// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) /
    ///        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector3Orthonormalize{ uVector, vVector, wVector, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Orthonormalize Mathematics::Vector3Tools<Real>::Orthonormalize(const ContainerType& vectors, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(vectors.size() == 3, "vectors的大小错误！");

    return Vector3Orthonormalize{ vectors, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalBasis Mathematics::Vector3Tools<Real>::GenerateOrthonormalBasis(const Vector3& nonzeroVector, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    return Vector3OrthonormalBasis{ nonzeroVector, false, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalBasis Mathematics::Vector3Tools<Real>::GenerateComplementBasis(const Vector3& unitVector, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(unitVector.IsNormalize(epsilon), "输入必须是单位向量！");

    return Vector3OrthonormalBasis{ unitVector, true, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector3Tools<Real>::LiftHomogeneous(const Vector3& vector, Real last) noexcept
{
    return Vector4{ vector.GetX(), vector.GetY(), vector.GetZ(), last };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector3Tools<Real>::Lift(const Vector3& vector, int inject, Real value)
{
    Vector4 result{};

    auto i = 0;
    for (; i < inject && i < Vector3::pointSize; ++i)
    {
        result[i] = vector[i];
    }
    result[i] = value;

    for (; i < Vector4::pointSize; ++i)
    {
        result[i + 1] = vector[i];
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector3Tools<Real>::ProjectHomogeneous(const Vector3& vector) noexcept
{
    return Vector2{ vector.GetX(), vector.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector3Tools<Real>::Project(const Vector3& vector, int reject)
{
    Vector2 result{};

    auto i = 0;
    auto j = 0;
    while (i < Vector2::pointSize)
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

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_ACHIEVE_H
