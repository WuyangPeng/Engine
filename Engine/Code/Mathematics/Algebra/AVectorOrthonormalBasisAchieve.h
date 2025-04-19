///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 10:17)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalBasis.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AVectorOrthonormalBasis<Real>::AVectorOrthonormalBasis(const AVectorType& nonzeroVector, bool isUnit, Real epsilon)
    : isUnit{ isUnit }, uVector{}, vVector{}, wVector{ nonzeroVector }, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "��������Ƿ���������");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AVectorOrthonormalBasis<Real>::Generate()
{
    if (!isUnit)
    {
        wVector.Normalize(epsilon);
    }

    if (MathType::FAbs(wVector.GetY() <= MathType::FAbs(wVector.GetX())))
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
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.x��unitVector.z����������ķ�������������
    const auto invLength = MathType::InvSqrt(wVector.GetX() * wVector.GetX() + wVector.GetZ() * wVector.GetZ());

    uVector = AVectorType{ -wVector.GetZ() * invLength, MathType::GetValue(0), wVector.GetX() * invLength };
    vVector = AVectorType{ wVector.GetY() * uVector.GetZ(), wVector.GetZ() * uVector.GetX() - wVector.GetX() * uVector.GetZ(), -wVector.GetY() * uVector.GetX() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.y��unitVector.z����������ķ�������������
    const auto invLength = MathType::InvSqrt(wVector.GetY() * wVector.GetY() + wVector.GetZ() * wVector.GetZ());

    uVector = AVectorType{ MathType::GetValue(0), wVector.GetZ() * invLength, -wVector.GetY() * invLength };
    vVector = AVectorType{ wVector.GetY() * uVector.GetZ() - wVector.GetZ() * uVector.GetY(), -wVector.GetX() * uVector.GetZ(), wVector.GetX() * uVector.GetY() };
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AVectorOrthonormalBasis<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::FAbs(Dot(uVector, vVector)) <= epsilon &&
            MathType::FAbs(Dot(uVector, wVector)) <= epsilon &&
            MathType::FAbs(Dot(vVector, wVector)) <= epsilon &&
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
typename Mathematics::AVectorOrthonormalBasis<Real>::AVectorType Mathematics::AVectorOrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AVectorOrthonormalBasis<Real>::AVectorType Mathematics::AVectorOrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AVectorOrthonormalBasis<Real>::AVectorType Mathematics::AVectorOrthonormalBasis<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_ACHIEVE_H