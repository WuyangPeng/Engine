// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 17:26)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DETAIL_H

#include "SingularValue.h"
#include "SingularValueDecomposition.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::SingularValue<Real>
	::SingularValue(const Matrix3& matrix)
	:m_Left{}, m_Diagonal{}, m_RightTranspose{}
{
	Calculate(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SingularValue<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::SingularValue<Real>
	::Calculate(const Matrix3& matrix)
{
	// ͨ�����������ֽ��QR�ֽ�ר�����3x3�ĸ�����
	// ����QDUDecomposition�ƺ��ٶ���������ǿ���ģ���һ���QR�ֽ���д�������Ⱦ���    

	VariableMatrix<Real> variableMatrix{ matrix };

	Mathematics::SingularValueDecomposition<Real> decomposition{ variableMatrix };

	m_Left = decomposition.GetLeftMatrix().GetMatrix3();
	m_Diagonal = decomposition.GetDiagonalMatrix().GetMatrix3();
	m_RightTranspose = decomposition.GetRightTransposeMatrix().GetMatrix3();
}

template <typename Real>
typename const Mathematics::SingularValue<Real>::Matrix3 Mathematics::SingularValue<Real>
	::GetLeftMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Left;
}

template <typename Real>
typename const Mathematics::SingularValue<Real>::Matrix3 Mathematics::SingularValue<Real>
	::GetDiagonalMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Diagonal;
}

template <typename Real>
typename const Mathematics::SingularValue<Real>::Matrix3 Mathematics::SingularValue<Real>
	::GetRightTransposeMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_RightTranspose;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DETAIL_H
