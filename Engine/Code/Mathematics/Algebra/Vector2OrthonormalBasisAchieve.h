///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 23:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_ACHIEVE_H

#include "Vector2Detail.h"
#include "Vector2OrthonormalBasis.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2OrthonormalBasis<Real>::Vector2OrthonormalBasis(const Vector2& nonzeroVector, const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : uVector{ nonzeroVector }, vVector{}, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Vector2OrthonormalBasis<Real>::Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    uVector.Normalize(epsilon);
    vVector = Vector2Tools::GetPerp(uVector);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Vector2OrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Vector2Tools::DotProduct(uVector, vVector)) <= epsilon &&
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
typename Mathematics::Vector2OrthonormalBasis<Real>::Vector2 Mathematics::Vector2OrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
typename Mathematics::Vector2OrthonormalBasis<Real>::Vector2 Mathematics::Vector2OrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_ACHIEVE_H