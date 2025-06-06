/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 14:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H

#include "QDUDecompositionValue.h"
#include "SingularValueDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QDUDecompositionValue<Real>::QDUDecompositionValue(const Matrix3Type& matrix)
    : orthogonal{}, diagonal{}, upperTriangular{}
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
void Mathematics::QDUDecompositionValue<Real>::Calculate(const Matrix3Type& matrix)
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
    auto invLength = MathType::InvSqrt(matrix.template GetValue<0, 0>() * matrix.template GetValue<0, 0>() + matrix.template GetValue<1, 0>() * matrix.template GetValue<1, 0>() + matrix.template GetValue<2, 0>() * matrix.template GetValue<2, 0>());

    orthogonal.template SetValue<0, 0>(matrix.template GetValue<0, 0>() * invLength);
    orthogonal.template SetValue<1, 0>(matrix.template GetValue<1, 0>() * invLength);
    orthogonal.template SetValue<2, 0>(matrix.template GetValue<2, 0>() * invLength);

    auto fDot = orthogonal.template GetValue<0, 0>() * matrix.template GetValue<0, 1>() + orthogonal.template GetValue<1, 0>() * matrix.template GetValue<1, 1>() + orthogonal.template GetValue<2, 0>() * matrix.template GetValue<2, 1>();

    orthogonal.template SetValue<0, 1>(matrix.template GetValue<0, 1>() - fDot * orthogonal.template GetValue<0, 0>());
    orthogonal.template SetValue<1, 1>(matrix.template GetValue<1, 1>() - fDot * orthogonal.template GetValue<1, 0>());
    orthogonal.template SetValue<2, 1>(matrix.template GetValue<2, 1>() - fDot * orthogonal.template GetValue<2, 0>());
    invLength = MathType::InvSqrt(orthogonal.template GetValue<0, 1>() * orthogonal.template GetValue<0, 1>() + orthogonal.template GetValue<1, 1>() * orthogonal.template GetValue<1, 1>() + orthogonal.template GetValue<2, 1>() * orthogonal.template GetValue<2, 1>());
    orthogonal(0, 1) *= invLength;
    orthogonal(1, 1) *= invLength;
    orthogonal(2, 1) *= invLength;

    fDot = orthogonal.template GetValue<0, 0>() * matrix.template GetValue<0, 2>() + orthogonal.template GetValue<1, 0>() * matrix.template GetValue<1, 2>() + orthogonal.template GetValue<2, 0>() * matrix.template GetValue<2, 2>();

    orthogonal(0, 2) = matrix.template GetValue<0, 2>() - fDot * orthogonal.template GetValue<0, 0>();
    orthogonal(1, 2) = matrix.template GetValue<1, 2>() - fDot * orthogonal.template GetValue<1, 0>();
    orthogonal(2, 2) = matrix.template GetValue<2, 2>() - fDot * orthogonal.template GetValue<2, 0>();
    fDot = orthogonal.template GetValue<0, 1>() * matrix.template GetValue<0, 2>() + orthogonal.template GetValue<1, 1>() * matrix.template GetValue<1, 2>() + orthogonal.template GetValue<2, 1>() * matrix.template GetValue<2, 2>();

    orthogonal(0, 2) -= fDot * orthogonal.template GetValue<0, 1>();
    orthogonal(1, 2) -= fDot * orthogonal.template GetValue<1, 1>();
    orthogonal(2, 2) -= fDot * orthogonal.template GetValue<2, 1>();

    invLength = MathType::InvSqrt(orthogonal.template GetValue<0, 2>() * orthogonal.template GetValue<0, 2>() + orthogonal.template GetValue<1, 2>() * orthogonal.template GetValue<1, 2>() + orthogonal.template GetValue<2, 2>() * orthogonal.template GetValue<2, 2>());
    orthogonal(0, 2) *= invLength;
    orthogonal(1, 2) *= invLength;
    orthogonal(2, 2) *= invLength;

    // 保证正交矩阵行列式1（无反射）
    auto det = orthogonal.Determinant();

    if (det < MathType::GetValue(0))
    {
        orthogonal = -orthogonal;
    }

    // 建立“右边”的矩阵Real.
    Matrix3Type right{};
    right(0, 0) = orthogonal.template GetValue<0, 0>() * matrix.template GetValue<0, 0>() + orthogonal.template GetValue<1, 0>() * matrix.template GetValue<1, 0>() + orthogonal.template GetValue<2, 0>() * matrix.template GetValue<2, 0>();

    right(0, 1) = orthogonal.template GetValue<0, 0>() * matrix.template GetValue<0, 1>() + orthogonal.template GetValue<1, 0>() * matrix.template GetValue<1, 1>() + orthogonal.template GetValue<2, 0>() * matrix.template GetValue<2, 1>();

    right(1, 1) = orthogonal.template GetValue<0, 1>() * matrix.template GetValue<0, 1>() + orthogonal.template GetValue<1, 1>() * matrix.template GetValue<1, 1>() + orthogonal.template GetValue<2, 1>() * matrix.template GetValue<2, 1>();

    right(0, 2) = orthogonal.template GetValue<0, 0>() * matrix.template GetValue<0, 2>() + orthogonal.template GetValue<1, 0>() * matrix.template GetValue<1, 2>() + orthogonal.template GetValue<2, 0>() * matrix.template GetValue<2, 2>();

    right(1, 2) = orthogonal.template GetValue<0, 1>() * matrix.template GetValue<0, 2>() + orthogonal.template GetValue<1, 1>() * matrix.template GetValue<1, 2>() + orthogonal.template GetValue<2, 1>() * matrix.template GetValue<2, 2>();

    right(2, 2) = orthogonal.template GetValue<0, 2>() * matrix.template GetValue<0, 2>() + orthogonal.template GetValue<1, 2>() * matrix.template GetValue<1, 2>() + orthogonal.template GetValue<2, 2>() * matrix.template GetValue<2, 2>();

    // 缩放组件。
    diagonal.MakeDiagonal(right.template GetValue<0, 0>(), right.template GetValue<1, 1>(), right.template GetValue<2, 2>());

    // 剪切组件。
    auto invD00 = MathType::GetValue(1) / diagonal.template GetValue<0, 0>();
    upperTriangular = Matrix3Type{ MathType::GetValue(1),
                               right.template GetValue<0, 1>() * invD00,
                               right(0, 2) * invD00,
                               MathType::GetValue(0),
                               MathType::GetValue(1),
                               right.template GetValue<1, 2>() / diagonal.template GetValue<1, 1>(),
                               MathType::GetValue(0),
                               MathType::GetValue(0),
                               MathType::GetValue(1) };
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3Type Mathematics::QDUDecompositionValue<Real>::GeOrthogonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return orthogonal;
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3Type Mathematics::QDUDecompositionValue<Real>::GetDiagonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return diagonal;
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3Type Mathematics::QDUDecompositionValue<Real>::GetUpperTriangularMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return upperTriangular;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H
