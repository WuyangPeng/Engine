///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:31)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H

#include "Matrix2Detail.h"
#include "Matrix2EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2EigenDecomposition<Real>::Matrix2EigenDecomposition(const Matrix2Type& rotation, const Matrix2Type& diagonal, Real epsilon) noexcept
    : rotation{ rotation }, diagonal{ diagonal }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Matrix2EigenDecomposition<Real>::IsValid() const noexcept
{
    if (MathType::FAbs(rotation.template GetValue<0, 0>() - rotation.template GetValue<1, 1>()) <= epsilon &&
        MathType::FAbs(rotation.template GetValue<0, 1>() + rotation.template GetValue<1, 0>()) <= epsilon &&
        MathType::FAbs(rotation.template GetValue<0, 0>() * rotation.template GetValue<1, 1>() - rotation.template GetValue<0, 1>() * rotation.template GetValue<1, 0>() - MathType::GetValue(1)) <= epsilon &&
        MathType::FAbs(diagonal.template GetValue<0, 1>() - MathType::GetValue(0)) <= epsilon &&
        MathType::FAbs(diagonal.template GetValue<1, 0>() - MathType::GetValue(0)) <= epsilon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2EigenDecomposition<Real>::Matrix2Type Mathematics::Matrix2EigenDecomposition<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rotation;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2EigenDecomposition<Real>::Matrix2Type Mathematics::Matrix2EigenDecomposition<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
