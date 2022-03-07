///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 23:46)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_ACHIEVE_H

#include "Vector2Detail.h"
#include "Vector2Orthonormalize.h"
#include "Vector2Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, bool Robust>
Mathematics::Vector2Orthonormalize<Real, Robust>::Vector2Orthonormalize(const Vector2& lhs, const Vector2& rhs, const Real epsilon)
    : uVector{ lhs }, vVector{ rhs }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, bool Robust>
void Mathematics::Vector2Orthonormalize<Real, Robust>::Generate()
{
    // 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
    //
    //   u0 = v0 / |v0|
    //   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    //
    // 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    // 计算 u0.
    if constexpr (Robust)
    {
        uVector.RobustNormalize(epsilon);
    }
    else
    {
        uVector.Normalize(epsilon);
    }

    // 计算 u1.
    const auto dot = Vector2Tools::DotProduct(uVector, vVector);

    MATHEMATICS_ASSERTION_1(epsilon < Math::FAbs(dot), "输入向量必须是线性无关的！");

    vVector -= uVector * dot;

    if constexpr (Robust)
    {
        vVector.RobustNormalize(epsilon);
    }
    else
    {
        vVector.Normalize(epsilon);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, bool Robust>
bool Mathematics::Vector2Orthonormalize<Real, Robust>::IsValid() const noexcept
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

template <typename Real, bool Robust>
const Mathematics::Vector2<Real> Mathematics::Vector2Orthonormalize<Real, Robust>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real, bool Robust>
const Mathematics::Vector2<Real> Mathematics::Vector2Orthonormalize<Real, Robust>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_ACHIEVE_H