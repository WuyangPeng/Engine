///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 10:17)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const AVector& uVector, const AVector& vVector, const AVector& wVector, Real epsilon)
    : uVector{ uVector }, vVector{ vVector }, wVector{ wVector }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const std::vector<AVector> vectors, Real epsilon)
    : uVector{ vectors.at(0) }, vVector{ vectors.at(1) }, wVector{ vectors.at(2) }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AVectorOrthonormalize<Real>::Generate()
{
    /// �����������v0��v1��v2����Gram-Schmidt������������ʸ��u0��u1��u2���£�
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// ����|A|��ʾ����A�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

    // ���� u0
    uVector.Normalize(epsilon);

#ifdef MATHEMATICS_PRECISION

    constexpr auto count = std::is_same_v<Real, float> ? MATHEMATICS_PRECISION : MATHEMATICS_PRECISION - 1;

    for (auto i = 0; i < count; ++i)

#endif  // MATHEMATICS_PRECISION

    {
        // ���� u1
        const auto dotUV = Dot(uVector, vVector);
        vVector -= (dotUV * uVector);
        vVector.Normalize(epsilon);

        // ���� u2
        const auto dotVW = Dot(vVector, wVector);
        const auto dotUW = Dot(uVector, wVector);
        wVector -= (dotUW * uVector + dotVW * vVector);
        wVector.Normalize(epsilon);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AVectorOrthonormalize<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::FAbs(Dot(uVector, vVector)) <= epsilon &&
            Math::FAbs(Dot(uVector, wVector)) <= epsilon &&
            Math::FAbs(Dot(vVector, wVector)) <= epsilon &&
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
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_ACHIEVE_H