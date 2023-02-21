///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 11:23)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H

#include "AVectorDetail.h"
#include "AVectorOrthonormalBasis.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AVectorOrthonormalBasis<Real>::AVectorOrthonormalBasis(const AVector& nonzeroVector, bool isUnit, const Real epsilon)
    : isUnit{ isUnit }, uVector{}, vVector{}, wVector{ nonzeroVector }, epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::Generate()
{
    if (!isUnit)
    {
        wVector.Normalize(epsilon);
    }

    if (Math::FAbs(wVector.GetY() <= Math::FAbs(wVector.GetX())))
    {
        GenerateOnXOrZIsMax();
    }
    else
    {
        GenerateOnYOrZIsMax();
    }
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.x或unitVector.z是最大量级的分量，交换他们
    const auto invLength = Math::InvSqrt(wVector.GetX() * wVector.GetX() + wVector.GetZ() * wVector.GetZ());

    uVector = AVector{ -wVector.GetZ() * invLength, Math::GetValue(0), wVector.GetX() * invLength };
    vVector = AVector{ wVector.GetY() * uVector.GetZ(), wVector.GetZ() * uVector.GetX() - wVector.GetX() * uVector.GetZ(), -wVector.GetY() * uVector.GetX() };
}

template <typename Real>
void Mathematics::AVectorOrthonormalBasis<Real>::GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // unitVector.y或unitVector.z是最大量级的分量，交换他们
    const auto invLength = Math::InvSqrt(wVector.GetY() * wVector.GetY() + wVector.GetZ() * wVector.GetZ());

    uVector = AVector{ Math::GetValue(0), wVector.GetZ() * invLength, -wVector.GetY() * invLength };
    vVector = AVector{ wVector.GetY() * uVector.GetZ() - wVector.GetZ() * uVector.GetY(), -wVector.GetX() * uVector.GetZ(), wVector.GetX() * uVector.GetY() };
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::AVectorOrthonormalBasis<Real>::IsValid() const noexcept
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
typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real>
typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real>
typename Mathematics::AVectorOrthonormalBasis<Real>::AVector Mathematics::AVectorOrthonormalBasis<Real>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_ACHIEVE_H