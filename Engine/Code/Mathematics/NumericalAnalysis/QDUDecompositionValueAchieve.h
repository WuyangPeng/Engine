///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:47)

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
void Mathematics::QDUDecompositionValue<Real>::Calculate(const Matrix3& matrix)
{
    // ����M = QR = QDU����Q����������ת����
    // D�ǶԽǣ����ţ�������U������Щ�����ĶԽ��ߣ����У������ǡ�
    // �㷨����ʩ����������QR���㷨����
    //
    // ��� M = [ m0 | m1 | m2 ] �� Q = [ q0 | q1 | q2 ], ��
    //
    //   q0 = m0/|m0|
    //   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
    //   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
    //
    // ����|V|��ʾʸ��V�ĳ��Ⱥ�A*B��ʾ����A��B�ĵ��
    //  ����Real������
    //
    //   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
    //   r10 = 0      r11 = q1*m1  r12 = q1*m2
    //   r20 = 0      r21 = 0      r22 = q2*m2
    //
    // ���� D = diag(r00,r11,r22) �� U ������ u01 = r01/r00,
    // u02 = r02/r00, �� u12 = r12/r11.

    // ������������Q.
    auto invLength = Math::InvSqrt(matrix.GetValue<0, 0>() * matrix.GetValue<0, 0>() + matrix.GetValue<1, 0>() * matrix.GetValue<1, 0>() + matrix.GetValue<2, 0>() * matrix.GetValue<2, 0>());

    orthogonal.SetValue<0, 0>(matrix.GetValue<0, 0>() * invLength);
    orthogonal.SetValue<1, 0>(matrix.GetValue<1, 0>() * invLength);
    orthogonal.SetValue<2, 0>(matrix.GetValue<2, 0>() * invLength);

    auto fDot = orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 1>() + orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 1>() + orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 1>();

    orthogonal.SetValue<0, 1>(matrix.GetValue<0, 1>() - fDot * orthogonal.GetValue<0, 0>());
    orthogonal.SetValue<1, 1>(matrix.GetValue<1, 1>() - fDot * orthogonal.GetValue<1, 0>());
    orthogonal.SetValue<2, 1>(matrix.GetValue<2, 1>() - fDot * orthogonal.GetValue<2, 0>());
    invLength = Math::InvSqrt(orthogonal.GetValue<0, 1>() * orthogonal.GetValue<0, 1>() + orthogonal.GetValue<1, 1>() * orthogonal.GetValue<1, 1>() + orthogonal.GetValue<2, 1>() * orthogonal.GetValue<2, 1>());
    orthogonal(0, 1) *= invLength;
    orthogonal(1, 1) *= invLength;
    orthogonal(2, 1) *= invLength;

    fDot = orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 2>() + orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 2>() + orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 2>();

    orthogonal(0, 2) = matrix.GetValue<0, 2>() - fDot * orthogonal.GetValue<0, 0>();
    orthogonal(1, 2) = matrix.GetValue<1, 2>() - fDot * orthogonal.GetValue<1, 0>();
    orthogonal(2, 2) = matrix.GetValue<2, 2>() - fDot * orthogonal.GetValue<2, 0>();
    fDot = orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 2>() + orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 2>() + orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 2>();

    orthogonal(0, 2) -= fDot * orthogonal.GetValue<0, 1>();
    orthogonal(1, 2) -= fDot * orthogonal.GetValue<1, 1>();
    orthogonal(2, 2) -= fDot * orthogonal.GetValue<2, 1>();

    invLength = Math::InvSqrt(orthogonal.GetValue<0, 2>() * orthogonal.GetValue<0, 2>() + orthogonal.GetValue<1, 2>() * orthogonal.GetValue<1, 2>() + orthogonal.GetValue<2, 2>() * orthogonal.GetValue<2, 2>());
    orthogonal(0, 2) *= invLength;
    orthogonal(1, 2) *= invLength;
    orthogonal(2, 2) *= invLength;

    // ��֤������������ʽ1���޷��䣩
    auto det = orthogonal.Determinant();

    if (det < Math::GetValue(0))
    {
        orthogonal = -orthogonal;
    }

    // �������ұߡ��ľ���Real.
    Matrix3 right{};
    right(0, 0) = orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 0>() + orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 0>() + orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 0>();

    right(0, 1) = orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 1>() + orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 1>() + orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 1>();

    right(1, 1) = orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 1>() + orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 1>() + orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 1>();

    right(0, 2) = orthogonal.GetValue<0, 0>() * matrix.GetValue<0, 2>() + orthogonal.GetValue<1, 0>() * matrix.GetValue<1, 2>() + orthogonal.GetValue<2, 0>() * matrix.GetValue<2, 2>();

    right(1, 2) = orthogonal.GetValue<0, 1>() * matrix.GetValue<0, 2>() + orthogonal.GetValue<1, 1>() * matrix.GetValue<1, 2>() + orthogonal.GetValue<2, 1>() * matrix.GetValue<2, 2>();

    right(2, 2) = orthogonal.GetValue<0, 2>() * matrix.GetValue<0, 2>() + orthogonal.GetValue<1, 2>() * matrix.GetValue<1, 2>() + orthogonal.GetValue<2, 2>() * matrix.GetValue<2, 2>();

    // ���������
    diagonal.MakeDiagonal(right.GetValue<0, 0>(), right.GetValue<1, 1>(), right.GetValue<2, 2>());

    // ���������
    auto invD00 = Math::GetValue(1) / diagonal.GetValue<0, 0>();
    upperTriangular = Matrix3{ Math::GetValue(1),
                               right.GetValue<0, 1>() * invD00,
                               right(0, 2) * invD00,
                               Math::GetValue(0),
                               Math::GetValue(1),
                               right.GetValue<1, 2>() / diagonal.GetValue<1, 1>(),
                               Math::GetValue(0),
                               Math::GetValue(0),
                               Math::GetValue(1) };
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GeOrthogonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return orthogonal;
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GetDiagonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return diagonal;
}

template <typename Real>
typename Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>::GetUpperTriangularMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return upperTriangular;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_ACHIEVE_H
