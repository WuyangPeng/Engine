// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 14:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_DETAIL_H

#include "PolarDecompositionValue.h"
#include "SingularValueDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolarDecompositionValue<Real>
	::PolarDecompositionValue(const Matrix3& matrix)
	:m_Orthogonal{}, m_Symmetry{}
{
	Calculate(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolarDecompositionValue<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::PolarDecompositionValue<Real>
	::Calculate(const Matrix3& matrix)
{
	// �ֽ� M = L * D * Real^T.
	SingularValue<Real> singularValue{ matrix };

	auto left = singularValue.GetLeftMatrix();
	auto diag = singularValue.GetDiagonalMatrix();
	auto rightTranspose = singularValue.GetRightTransposeMatrix();

	// �ֽ� Q = L * Real^T.
	m_Orthogonal = left * rightTranspose;

	// �ֽ� S = Real * D * Real^T.
	m_Symmetry = TransposeTimes(rightTranspose, diag * rightTranspose);

	// ��ֵ�������ᵼ�²��ǶԳƵģ�
	// ��S[i][j] ��S[j][i]]���в�ͬ,��i != j��
	// ͨ��ƽ��S = (S + S^T)/2������
	m_Symmetry(0, 1) =  Math::GetRational(1,2) * (m_Symmetry(0, 1) + m_Symmetry(1, 0));
	m_Symmetry(1, 0) = m_Symmetry(0, 1);
	m_Symmetry(0, 2) =  Math::GetRational(1,2) * (m_Symmetry(0, 2) + m_Symmetry(2, 0));
	m_Symmetry(2, 0) = m_Symmetry(0, 2);
	m_Symmetry(1, 2) =  Math::GetRational(1,2) * (m_Symmetry(1, 2) + m_Symmetry(2, 1));
	m_Symmetry(2, 1) = m_Symmetry(1, 2);
}

template <typename Real>
typename const Mathematics::PolarDecompositionValue<Real>::Matrix3 Mathematics::PolarDecompositionValue<Real>
	::GeOrthogonalMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Orthogonal;
}

template <typename Real>
typename const Mathematics::PolarDecompositionValue<Real>::Matrix3 Mathematics::PolarDecompositionValue<Real>
	::GetSymmetryMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Symmetry;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_DETAIL_H
