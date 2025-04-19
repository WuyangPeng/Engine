///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_ACHIEVE_H

#include "Vector3Detail.h"
#include "Vector3OrthonormalBasis.h"
#include "Vector3Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3OrthonormalBasis<Real>::Vector3OrthonormalBasis(const Vector3Type& nonzeroVector, bool isUnit, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : isUnit{ isUnit }, uVector{}, vVector{}, wVector{ nonzeroVector }, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3OrthonormalBasis<Real>::Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    if (!isUnit)
    {
        wVector.Normalize(epsilon);
    }

    if (MathType::FAbs(wVector.GetY()) <= MathType::FAbs(wVector.GetX()))
    {
        GenerateOnXOrZIsMax();
    }
    else
    {
        GenerateOnYOrZIsMax();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3OrthonormalBasis<Real>::GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.x或unitVector.z是大小最大的组成部分，交换他们
    const auto invLength = MathType::InvSqrt(wVector.GetX() * wVector.GetX() + wVector.GetZ() * wVector.GetZ());

    uVector = Vector3Type{ -wVector.GetZ() * invLength, MathType::GetValue(0), wVector.GetX() * invLength };

    vVector = Vector3Type{ wVector.GetY() * uVector.GetZ(), wVector.GetZ() * uVector.GetX() - wVector.GetX() * uVector.GetZ(), -wVector.GetY() * uVector.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3OrthonormalBasis<Real>::GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.y或unitVector.z是大小最大的组成部分，交换他们
    const auto invLength = MathType::InvSqrt(wVector.GetY() * wVector.GetY() + wVector.GetZ() * wVector.GetZ());

    uVector = Vector3Type{ MathType::GetValue(0), wVector.GetZ() * invLength, -wVector.GetY() * invLength };

    vVector = Vector3Type{ wVector.GetY() * uVector.GetZ() - wVector.GetZ() * uVector.GetY(), -wVector.GetX() * uVector.GetZ(), wVector.GetX() * uVector.GetY() };
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3OrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::FAbs(Vector3ToolsType::DotProduct(uVector, vVector)) <= epsilon &&
            MathType::FAbs(Vector3ToolsType::DotProduct(uVector, wVector)) <= epsilon &&
            MathType::FAbs(Vector3ToolsType::DotProduct(vVector, wVector)) <= epsilon &&
            uVector.IsNormalize(epsilon) &&
            vVector.IsNormalize(epsilon) &&
            wVector.IsNormalize(epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3OrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3OrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3OrthonormalBasis<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_ACHIEVE_H