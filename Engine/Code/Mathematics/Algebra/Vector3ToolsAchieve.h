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
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Tools<Real>::Approximate(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

    return MathType::FAbs(lhs.GetX() - rhs.GetX()) < epsilon &&
           MathType::FAbs(lhs.GetY() - rhs.GetY()) < epsilon &&
           MathType::FAbs(lhs.GetZ() - rhs.GetZ()) < epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetRobustLength(const Vector3Type& vector)
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
Real Mathematics::Vector3Tools<Real>::GetLength(const Vector3Type& vector) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(GetLengthSquared(vector));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetLengthSquared(const Vector3Type& vector) noexcept
{
    return vector.GetX() * vector.GetX() + vector.GetY() * vector.GetY() + vector.GetZ() * vector.GetZ();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::DotProduct(const Vector3Type& lhs, const Vector3Type& rhs) noexcept
{
    return (lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::CrossProduct(const Vector3Type& lhs, const Vector3Type& rhs) noexcept
{
    return Vector3Type{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                    lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                    lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::CrossProductWithReduceMultiplication(const Vector3Type& lhs, const Vector3Type& rhs) noexcept
{
    const auto t1 = lhs.GetX() - lhs.GetY();
    const auto t2 = rhs.GetY() + rhs.GetZ();
    const auto t3 = lhs.GetX() * rhs.GetZ();
    const auto t4 = t1 * t2 - t3;

    return Vector3Type{ rhs.GetY() * (t1 - lhs.GetZ()) - t4,
                    lhs.GetZ() * rhs.GetX() - t3,
                    t4 - lhs.GetY() * (rhs.GetX() - t2) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::UnitCrossProduct(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    auto cross = CrossProduct(lhs, rhs);
    cross.Normalize(epsilon);

    return cross;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::Distance(const Vector3Type& lhs, const Vector3Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::DistanceSquared(const Vector3Type& lhs, const Vector3Type& rhs) noexcept
{
    const auto distanceX = lhs.GetX() - rhs.GetX();
    const auto distanceY = lhs.GetY() - rhs.GetY();
    const auto distanceZ = lhs.GetZ() - rhs.GetZ();

    return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::ParallelVectorLhsToRhs(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon)
{
    const auto moduleSquare = GetLengthSquared(rhs);

    if (epsilon < moduleSquare)
    {
        return rhs * (DotProduct(lhs, rhs) / moduleSquare);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        return Vector3Type();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::ApeakVectorLhsToRhs(const Vector3Type& lhs, const Vector3Type& rhs, Real epsilon)
{
    return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::ReflectionVector(const Vector3Type& ray, const Vector3Type& normal)
{
    return 2 * DotProduct(normal, ray) * normal - ray;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::RefractionVector(const Vector3Type& ray, const Vector3Type& normal, Real consistencyRatio)
{
    MATHEMATICS_ASSERTION_1(consistencyRatio <= 1, "consistencyRatio必须小于或等于1！");

    const auto cosphi = DotProduct(-ray, normal);
    const auto conphiSquare = cosphi * cosphi;
    const auto consistencyRatioSquare = consistencyRatio * consistencyRatio;
    const auto costheta = 1 / consistencyRatioSquare * MathType::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

    return consistencyRatio * ray - (costheta + consistencyRatio * cosphi) * normal;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::FeatheringOutZAxes(const Vector3Type& vector, Function function)
{
    if (function != nullptr)
    {
        const auto r = function(vector.GetZ());

        return Vector3Type{ vector.GetX() * r, vector.GetY() * r, vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::TwistZAxes(const Vector3Type& vector, Function function)
{
    if (function != nullptr)
    {
        const auto delta = function(vector.GetZ());

        return Vector3Type{ vector.GetX() * MathType::Cos(delta) - vector.GetY() * MathType::Sin(delta),
                        vector.GetX() * MathType::Sin(delta) - vector.GetY() * MathType::Cos(delta),
                        vector.GetZ() };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3Type Mathematics::Vector3Tools<Real>::BendYAxes(const Vector3Type& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_ASSERTION_1(bendAreaMin <= bendAreaMax, "bendAreaMin值必须小于或等于bendAreaMax！");

    auto y = vector.GetY();

    if (vector.GetY() <= bendAreaMin)
        y = bendAreaMin;
    else if (vector.GetY() >= bendAreaMax)
        y = bendAreaMax;

    const auto delta = 1 / curvatureRadius * (y - bendCenter);

    Vector3Type bendVector{};

    bendVector.SetX(vector.GetX());

    if (bendAreaMin <= vector.GetY() && vector.GetY() <= bendAreaMax)
    {
        bendVector.SetY(-MathType::Sin(delta) * (vector.GetZ() - curvatureRadius) + bendCenter);
        bendVector.SetZ(-MathType::Cos(delta) * (vector.GetZ() - curvatureRadius) + bendCenter);
    }
    else if (vector.GetY() < bendAreaMin)
    {
        bendVector.SetY(-MathType::Sin(delta) * (vector.GetZ() - curvatureRadius) + bendCenter + MathType::Cos(delta) * (vector.GetY() - bendAreaMin));

        bendVector.SetZ(-MathType::Cos(delta) * (vector.GetZ() - curvatureRadius) + bendCenter + MathType::Sin(delta) * (vector.GetY() - bendAreaMin));
    }
    else if (bendAreaMax < vector.GetY())
    {
        bendVector.SetY(-MathType::Sin(delta) * (vector.GetZ() - curvatureRadius) + curvatureRadius + MathType::Cos(delta) * (vector.GetY() - bendAreaMax));

        bendVector.SetZ(-MathType::Cos(delta) * (vector.GetZ() - curvatureRadius) + curvatureRadius + MathType::Sin(delta) * (vector.GetY() - bendAreaMax));
    }

    return bendVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::ScalarTripleProduct(const Vector3Type& vector0, const Vector3Type& vector1, const Vector3Type& vector2) noexcept
{
    return DotProduct(CrossProduct(vector0, vector1), vector2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Tools<Real>::GetVectorIncludedAngle(const Vector3Type& lhs, const Vector3Type& rhs) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    return MathType::ACos(DotProduct(lhs, rhs) / (GetLength(lhs) * GetLength(rhs)));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::AxesAlignBoundingBox3D Mathematics::Vector3Tools<Real>::ComputeExtremes(const ContainerType& vectors)
{
    Vector3Type min{ MathType::maxReal, MathType::maxReal, MathType::maxReal };
    Vector3Type max{ MathType::minReal, MathType::minReal, MathType::minReal };

    for (const auto& eachVector : vectors)
    {
        for (auto i = 0; i < Vector3Type::pointSize; ++i)
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
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalizeType Mathematics::Vector3Tools<Real>::Orthonormalize(const Vector3Type& uVector, const Vector3Type& vVector, const Vector3Type& wVector, const Real epsilon)
{
    /// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) /
    ///        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    return Vector3OrthonormalizeType{ uVector, vVector, wVector, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalizeType Mathematics::Vector3Tools<Real>::Orthonormalize(const ContainerType& vectors, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(vectors.size() == 3, "vectors的大小错误！");

    return Vector3OrthonormalizeType{ vectors, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalBasisType Mathematics::Vector3Tools<Real>::GenerateOrthonormalBasis(const Vector3Type& nonzeroVector, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    return Vector3OrthonormalBasisType{ nonzeroVector, false, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalBasisType Mathematics::Vector3Tools<Real>::GenerateComplementBasis(const Vector3Type& unitVector, Real epsilon)
{
    MATHEMATICS_ASSERTION_0(unitVector.IsNormalize(epsilon), "输入必须是单位向量！");

    return Vector3OrthonormalBasisType{ unitVector, true, epsilon };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector3Tools<Real>::LiftHomogeneous(const Vector3Type& vector, Real last) noexcept
{
    return Vector4Type{ vector.GetX(), vector.GetY(), vector.GetZ(), last };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector3Tools<Real>::Lift(const Vector3Type& vector, int inject, Real value)
{
    Vector4Type result{};

    auto i = 0;
    for (; i < inject && i < Vector3Type::pointSize; ++i)
    {
        result[i] = vector[i];
    }
    result[i] = value;

    for (; i < Vector4Type::pointSize; ++i)
    {
        result[i + 1] = vector[i];
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector3Tools<Real>::ProjectHomogeneous(const Vector3Type& vector) noexcept
{
    return Vector2Type{ vector.GetX(), vector.GetY() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector3Tools<Real>::Project(const Vector3Type& vector, int reject)
{
    Vector2Type result{};

    auto i = 0;
    auto j = 0;
    while (i < Vector2Type::pointSize)
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
typename Mathematics::Vector3Tools<Real>::Vector3OrthonormalizeType Mathematics::Vector3Tools<Real>::ComputeOrthogonalComplement(int numInputs, const ArrayType& vector)
{
    auto uVector = vector.at(0);
    auto vVector = vector.at(1);
    auto wVector = vector.at(2);

    if (numInputs == 1)
    {
        if (MathType::FAbs(uVector[0]) > MathType::FAbs(uVector[1]))
        {
            vVector = { -uVector[2], Real{}, +uVector[0] };
        }
        else
        {
            vVector = { Real{}, +uVector[2], -uVector[1] };
        }
        numInputs = 2;
    }

    if (numInputs == 2)
    {
        wVector = CrossProduct(uVector, vVector);
    }

    return Orthonormalize(uVector, vVector, wVector);
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_ACHIEVE_H
