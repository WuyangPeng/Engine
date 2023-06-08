///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 16:41)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H

#include "Matrix2Detail.h"
#include "Matrix2EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Matrix2EigenDecomposition<Real>::Matrix2EigenDecomposition(const Matrix2& rotation, const Matrix2& diagonal, Real epsilon) noexcept
    : rotation{ rotation }, diagonal{ diagonal }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Matrix2EigenDecomposition<Real>::IsValid() const noexcept
{
    if (Math::FAbs(rotation.GetValue<0, 0>() - rotation.GetValue<1, 1>()) <= epsilon &&
        Math::FAbs(rotation.GetValue<0, 1>() + rotation.GetValue<1, 0>()) <= epsilon &&
        Math::FAbs(rotation.GetValue<0, 0>() * rotation.GetValue<1, 1>() - rotation.GetValue<0, 1>() * rotation.GetValue<1, 0>() - Math::GetValue(1)) <= epsilon &&
        Math::FAbs(diagonal.GetValue<0, 1>() - Math::GetValue(0)) <= epsilon &&
        Math::FAbs(diagonal.GetValue<1, 0>() - Math::GetValue(0)) <= epsilon)
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
typename Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rotation;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
