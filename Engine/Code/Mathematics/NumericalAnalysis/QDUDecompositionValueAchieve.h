///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/29 21:14)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H

#include "QDUDecompositionValue.h"
#include "SingularValueDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QDUDecompositionValue<Real>::QDUDecompositionValue(const Matrix3& matrix)
    : m_Orthogonal{}, m_Diagonal{}, m_UpperTriangular{}
{
    Calculate(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QDUDecompositionValue<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::QDUDecompositionValue<Real>::Calculate(const Matrix3& matrix)
{
    // 因子M = QR = QDU其中Q是正交（旋转），
    // D是对角（缩放），并且U是与那些在它的对角线（剪切）上三角。
    // 算法采用施密特正交（QR的算法）。
    //
    // 如果 M = [ m0 | m1 | m2 ] 和 Q = [ q0 | q1 | q2 ], 则
    //
    //   q0 = m0/|m0|
    //   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
    //   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
    //
    // 其中|V|表示矢量V的长度和A*B表示向量A和B的点积
    //  矩阵Real具有项
    //
    //   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
    //   r10 = 0      r11 = q1*m1  r12 = q1*m2
    //   r20 = 0      r21 = 0      r22 = q2*m2
    //
    // 所以 D = diag(r00,r11,r22) 和 U 具有项 u01 = r01/r00,
    // u02 = r02/r00, 和 u12 = r12/r11.

    // 构建正交矩阵Q.
    auto invLength = Math::InvSqrt(matrix.GetValue<0, 0>() * matrix.GetValue<0, 0>() + matrix.GetValue<1, 0>() * matrix.GetValue<1, 0>() + matrix.GetValue<2, 0>() * matrix.GetValue<2, 0>());

    m_Orthogonal.SetValue<0, 0>(matrix.GetValue<0, 0>() * invLength);
    m_Orthogonal.SetValue<1, 0>(matrix.GetValue<1, 0>() * invLength);
    m_Orthogonal.SetValue<2, 0>(matrix.GetValue<2, 0>() * invLength);

    auto fDot = m_Orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 1>() + m_Orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 1>() + m_Orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 1>();

    m_Orthogonal.SetValue<0, 1>(matrix.GetValue<0, 1>() - fDot * m_Orthogonal.GetValue<0, 0>());
    m_Orthogonal.SetValue<1, 1>(matrix.GetValue<1, 1>() - fDot * m_Orthogonal.GetValue<1, 0>());
    m_Orthogonal.SetValue<2, 1>(matrix.GetValue<2, 1>() - fDot * m_Orthogonal.GetValue<2, 0>());
    invLength = Math::InvSqrt(m_Orthogonal.GetValue<0, 1>() * m_Orthogonal.GetValue<0, 1>() + m_Orthogonal.GetValue<1, 1>() * m_Orthogonal.GetValue<1, 1>() + m_Orthogonal.GetValue<2, 1>() * m_Orthogonal.GetValue<2, 1>());
    m_Orthogonal(0, 1) *= invLength;
    m_Orthogonal(1, 1) *= invLength;
    m_Orthogonal(2, 1) *= invLength;

    fDot = m_Orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 2>();

    m_Orthogonal(0, 2) = matrix.GetValue<0, 2>() - fDot * m_Orthogonal.GetValue<0, 0>();
    m_Orthogonal(1, 2) = matrix.GetValue<1, 2>() - fDot * m_Orthogonal.GetValue<1, 0>();
    m_Orthogonal(2, 2) = matrix.GetValue<2, 2>() - fDot * m_Orthogonal.GetValue<2, 0>();
    fDot = m_Orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 2>();

    m_Orthogonal(0, 2) -= fDot * m_Orthogonal.GetValue<0, 1>();
    m_Orthogonal(1, 2) -= fDot * m_Orthogonal.GetValue<1, 1>();
    m_Orthogonal(2, 2) -= fDot * m_Orthogonal.GetValue<2, 1>();

    invLength = Math::InvSqrt(m_Orthogonal.GetValue<0, 2>() * m_Orthogonal.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 2>() * m_Orthogonal.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 2>() * m_Orthogonal.GetValue<2, 2>());
    m_Orthogonal(0, 2) *= invLength;
    m_Orthogonal(1, 2) *= invLength;
    m_Orthogonal(2, 2) *= invLength;

    // 保证正交矩阵行列式1（无反射）
    auto det = m_Orthogonal.Determinant();

    if (det < Math::GetValue(0))
    {
        m_Orthogonal = -m_Orthogonal;
    }

    // 建立“右边”的矩阵Real.
    Matrix3 right{};
    right(0, 0) = m_Orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 0>() + m_Orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 0>() + m_Orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 0>();

    right(0, 1) = m_Orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 1>() + m_Orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 1>() + m_Orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 1>();

    right(1, 1) = m_Orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 1>() + m_Orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 1>() + m_Orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 1>();

    right(0, 2) = m_Orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 2>();

    right(1, 2) = m_Orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 2>();

    right(2, 2) = m_Orthogonal.GetValue<0, 2>() * matrix.GetValue<0, 2>() + m_Orthogonal.GetValue<1, 2>() * matrix.GetValue<1, 2>() + m_Orthogonal.GetValue<2, 2>() * matrix.GetValue<2, 2>();

    // 缩放组件。
    m_Diagonal.MakeDiagonal(right.GetValue<0, 0>(), right.GetValue<1, 1>(), right.GetValue<2, 2>());

    // 剪切组件。
    auto invD00 = Math::GetValue(1) / m_Diagonal.GetValue<0, 0>();
    m_UpperTriangular = Matrix3{ Math::GetValue(1), right.GetValue<0, 1>() * invD00, right(0, 2) * invD00,
                                 Math::GetValue(0), Math::GetValue(1), right.GetValue<1, 2>() / m_Diagonal.GetValue<1, 1>(),
                                 Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GeOrthogonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Orthogonal;
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GetDiagonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Diagonal;
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GetUpperTriangularMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_UpperTriangular;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H
