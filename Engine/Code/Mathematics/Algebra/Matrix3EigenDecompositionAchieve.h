///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 17:02)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE_H

#include "Matrix3Detail.h"
#include "Matrix3EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Matrix3EigenDecomposition<Real>::Matrix3EigenDecomposition(const Matrix3& rotation, const Matrix3& diagonal, const Real epsilon) noexcept
    : rotation{ rotation }, diagonal{ diagonal }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Matrix3EigenDecomposition<Real>::IsValid() const noexcept
{
    if (Math::FAbs(diagonal.GetValue<0, 1>()) <= epsilon &&
        Math::FAbs(diagonal.GetValue<0, 2>()) <= epsilon &&
        Math::FAbs(diagonal.GetValue<1, 0>()) <= epsilon &&
        Math::FAbs(diagonal.GetValue<1, 2>()) <= epsilon &&
        Math::FAbs(diagonal.GetValue<2, 0>()) <= epsilon &&
        Math::FAbs(diagonal.GetValue<2, 1>()) <= epsilon)
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
typename Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rotation;
}

template <typename Real>
typename Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE_H
