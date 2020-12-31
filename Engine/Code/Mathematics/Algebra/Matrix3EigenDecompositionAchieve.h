///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 18:48)

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
    : m_Rotation{ rotation }, m_Diagonal{ diagonal }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix3EigenDecomposition<Real>::IsValid() const noexcept
{
    if (Math::FAbs(m_Diagonal.GetValue<0, 1>()) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<0, 2>()) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<1, 0>()) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<1, 2>()) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<2, 0>()) <= m_Epsilon &&
        Math::FAbs(m_Diagonal.GetValue<2, 1>()) <= m_Epsilon)
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
typename const Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rotation;
}

template <typename Real>
typename const Mathematics::Matrix3EigenDecomposition<Real>::Matrix3 Mathematics::Matrix3EigenDecomposition<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE_H
