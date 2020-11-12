///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 14:07)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H

#include "Matrix2Detail.h"
#include "Matrix2EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Matrix2EigenDecomposition<Real>::Matrix2EigenDecomposition(const Matrix2& rotation, const Matrix2& diagonal, const Real epsilon) noexcept
    : m_Rotation{ rotation }, m_Diagonal{ diagonal }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix2EigenDecomposition<Real>::IsValid() const noexcept
{
    if (Math::FAbs(m_Rotation.GetValue<0, 0>() - m_Rotation.GetValue<1, 1>()) <= m_Epsilon &&
        Math::FAbs(m_Rotation.GetValue<0, 1>() + m_Rotation.GetValue<1, 0>()) <= m_Epsilon &&
        Math::FAbs(m_Rotation.GetValue<0, 0>() * m_Rotation.GetValue<1, 1>() - m_Rotation.GetValue<0, 1>() * m_Rotation.GetValue<1, 0>() - Math::GetValue(1)) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<0, 1>() - Math::GetValue(0)) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<1, 0>() - Math::GetValue(0)) <= m_Epsilon)
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
typename const Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rotation;
}

template <typename Real>
typename const Mathematics::Matrix2EigenDecomposition<Real>::Matrix2 Mathematics::Matrix2EigenDecomposition<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_ACHIEVE_H
