///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 10:23)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_ACHIEVE_H

#include "PolarDecompositionValue.h"
#include "SingularValueDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::PolarDecompositionValue<Real>::PolarDecompositionValue(const Matrix3& matrix)
    : orthogonal{}, symmetry{}
{
    Calculate(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolarDecompositionValue<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::PolarDecompositionValue<Real>::Calculate(const Matrix3& matrix)
{
    // �ֽ� M = L * D * Real^T.
    const SingularValue<Real> singularValue{ matrix };

    const auto left = singularValue.GetLeftMatrix();
    const auto diag = singularValue.GetDiagonalMatrix();
    const auto rightTranspose = singularValue.GetRightTransposeMatrix();

    // �ֽ� Q = L * Real^T.
    orthogonal = left * rightTranspose;

    // �ֽ� S = Real * D * Real^T.
    symmetry = TransposeTimes(rightTranspose, diag * rightTranspose);

    // ��ֵ�������ᵼ�²��ǶԳƵģ�
    // ��S[i][j] ��S[j][i]]���в�ͬ,��i != j��
    // ͨ��ƽ��S = (S + S^T)/2������
    symmetry(0, 1) = Math::GetRational(1, 2) * (symmetry(0, 1) + symmetry(1, 0));
    symmetry(1, 0) = symmetry(0, 1);
    symmetry(0, 2) = Math::GetRational(1, 2) * (symmetry(0, 2) + symmetry(2, 0));
    symmetry(2, 0) = symmetry(0, 2);
    symmetry(1, 2) = Math::GetRational(1, 2) * (symmetry(1, 2) + symmetry(2, 1));
    symmetry(2, 1) = symmetry(1, 2);
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::PolarDecompositionValue<Real>::GeOrthogonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return orthogonal;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::PolarDecompositionValue<Real>::GetSymmetryMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return symmetry;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_ACHIEVE_H
