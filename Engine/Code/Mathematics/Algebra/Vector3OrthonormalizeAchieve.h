///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:17)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H

#include "Vector3Detail.h"
#include "Vector3Orthonormalize.h"
#include "Vector3Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Orthonormalize<Real, Robust>::Vector3Orthonormalize(const Vector3& uVector, const Vector3& vVector, const Vector3& wVector, const Real epsilon)
    : uVector{ uVector }, vVector{ vVector }, wVector{ wVector }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Orthonormalize<Real, Robust>::Vector3Orthonormalize(const ContainerType& vectors, const Real epsilon)
    : uVector{ vectors.at(Vector3::xIndex) }, vVector{ vectors.at(Vector3::yIndex) }, wVector{ vectors.at(Vector3::zIndex) }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Orthonormalize<Real, Robust>::Generate()
{
    /// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

    // 计算 u0
    if constexpr (Robust)
    {
        uVector.RobustNormalize(epsilon);
    }
    else
    {
        uVector.Normalize(epsilon);
    }

    // 计算 u1
    const auto dotUV = Vector3Tools::DotProduct(uVector, vVector);

    MATHEMATICS_ASSERTION_1(epsilon < Math::FAbs(dotUV), "输入向量必须是线性无关的！");

    vVector -= dotUV * uVector;
    if constexpr (Robust)
    {
        vVector.RobustNormalize(epsilon);
    }
    else
    {
        vVector.Normalize(epsilon);
    }

    // 计算 u2
    const auto dotVW = Vector3Tools::DotProduct(vVector, wVector);
    const auto dotUW = Vector3Tools::DotProduct(uVector, wVector);

    wVector -= dotUW * uVector + dotVW * vVector;
    if constexpr (Robust)
    {
        wVector.RobustNormalize(epsilon);
    }
    else
    {
        wVector.Normalize(epsilon);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Orthonormalize<Real, Robust>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Vector3Tools::DotProduct(uVector, vVector)) <= epsilon &&
            Math::FAbs(Vector3Tools::DotProduct(uVector, wVector)) <= epsilon &&
            Math::FAbs(Vector3Tools::DotProduct(vVector, wVector)) <= epsilon &&
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

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H