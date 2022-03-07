///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 11:24)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const AVector& uVector, const AVector& vVector, const AVector& wVector, const Real epsilon)
    : uVector{ uVector }, vVector{ vVector }, wVector{ wVector }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::AVectorOrthonormalize<Real>::AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon)
    : uVector{ vectors.at(0) }, vVector{ vectors.at(1) }, wVector{ vectors.at(2) }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
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

    // ���� u1
    const auto dotUV = Dot(uVector, vVector);
    vVector -= dotUV * uVector;
    vVector.Normalize(epsilon);

    // ���� u2
    const auto dotVW = Dot(vVector, wVector);
    const auto dotUW = Dot(uVector, wVector);
    wVector -= dotUW * uVector + dotVW * vVector;
    wVector.Normalize(epsilon);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::AVectorOrthonormalize<Real>::IsValid() const noexcept
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
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real>
typename Mathematics::AVectorOrthonormalize<Real>::AVector Mathematics::AVectorOrthonormalize<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_ACHIEVE_H