///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:15)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_ACHIEVE_H

#include "Vector2Detail.h"
#include "Vector2OrthonormalBasis.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2OrthonormalBasis<Real>::Vector2OrthonormalBasis(const Vector2Type& nonzeroVector, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : uVector{ nonzeroVector }, vVector{}, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2OrthonormalBasis<Real>::Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    uVector.Normalize(epsilon);
    vVector = Vector2ToolsType::GetPerp(uVector);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2OrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::FAbs(Vector2ToolsType::DotProduct(uVector, vVector)) <= epsilon &&
            uVector.IsNormalize(epsilon) &&
            vVector.IsNormalize(epsilon))
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
typename Mathematics::Vector2OrthonormalBasis<Real>::Vector2Type Mathematics::Vector2OrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2OrthonormalBasis<Real>::Vector2Type Mathematics::Vector2OrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_ACHIEVE_H