///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 11:37)

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
    : m_Orthogonal{}, m_Symmetry{}
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

// private
template <typename Real>
void Mathematics::PolarDecompositionValue<Real>::Calculate(const Matrix3& matrix)
{
    // �ֽ� M = L * D * Real^T.
    const SingularValue<Real> singularValue{ matrix };

    const auto left = singularValue.GetLeftMatrix();
    const auto diag = singularValue.GetDiagonalMatrix();
    const auto rightTranspose = singularValue.GetRightTransposeMatrix();

    // �ֽ� Q = L * Real^T.
    m_Orthogonal = left * rightTranspose;

    // �ֽ� S = Real * D * Real^T.
    m_Symmetry = TransposeTimes(rightTranspose, diag * rightTranspose);

    // ��ֵ�������ᵼ�²��ǶԳƵģ�
    // ��S[i][j] ��S[j][i]]���в�ͬ,��i != j��
    // ͨ��ƽ��S = (S + S^T)/2������
    m_Symmetry(0, 1) = Math::GetRational(1, 2) * (m_Symmetry(0, 1) + m_Symmetry(1, 0));
    m_Symmetry(1, 0) = m_Symmetry(0, 1);
    m_Symmetry(0, 2) = Math::GetRational(1, 2) * (m_Symmetry(0, 2) + m_Symmetry(2, 0));
    m_Symmetry(2, 0) = m_Symmetry(0, 2);
    m_Symmetry(1, 2) = Math::GetRational(1, 2) * (m_Symmetry(1, 2) + m_Symmetry(2, 1));
    m_Symmetry(2, 1) = m_Symmetry(1, 2);
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::PolarDecompositionValue<Real>::GeOrthogonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Orthogonal;
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::PolarDecompositionValue<Real>::GetSymmetryMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Symmetry;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_ACHIEVE_H
