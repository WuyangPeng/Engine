// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 14:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H

#include "LinearSystem.h"
#include "SolveBandedDetail.h"
#include "LinearSystemInverseDetail.h"
#include "BandedMatrixInvertDetail.h"
#include "SolveSymmetricConjugateGradientDetail.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::LinearSystem<Real>
	::LinearSystem(Real zeroTolerance)
	:m_ZeroTolerance{ zeroTolerance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::LinearSystem<Real>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_ZeroTolerance)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SetZeroTolerance(Real zeroTolerance)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_ZeroTolerance = zeroTolerance;
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve2(const Real matrix[2][2], const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (matrix == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}

	if (matrix[0] == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}

	if (matrix[1] == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}

	if (inputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("inputVectorָ��Ϊ�գ�"));
	}
	if (outputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputVectorָ��Ϊ�գ�"));
	}

	auto det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	if (Math::FAbs(det) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Solve2 ʧ�ܣ�detΪ0��"));
	}

	outputVector[0] = (matrix[1][1] * inputVector[0] - matrix[0][1] * inputVector[1]) / det;
	outputVector[1] = (matrix[0][0] * inputVector[1] - matrix[1][0] * inputVector[0]) / det;
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve3(const Real matrix[3][3], const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (matrix == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}
	if (matrix[0] == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}
	if (matrix[1] == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}
	if (matrix[2] == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("matrixָ��Ϊ�գ�"));
	}
	if (inputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("inputVectorָ��Ϊ�գ�"));
	}
	if (outputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputVectorָ��Ϊ�գ�"));
	}

	Real invMatrix[3][3];
	invMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	invMatrix[0][1] = matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2];
	invMatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	invMatrix[1][0] = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
	invMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	invMatrix[1][2] = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
	invMatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	invMatrix[2][1] = matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1];
	invMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	auto det = matrix[0][0] * invMatrix[0][0] + matrix[0][1] * invMatrix[1][0] + matrix[0][2] * invMatrix[2][0];

	if (Math::FAbs(det) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Solve3 ʧ�ܣ�detΪ0��"));
	}

	for (auto row = 0; row < 3; ++row)
	{
		for (auto col = 0; col < 3; ++col)
		{
			invMatrix[row][col] /= det;
		}
	}

	outputVector[0] = invMatrix[0][0] * inputVector[0] + invMatrix[0][1] * inputVector[1] + invMatrix[0][2] * inputVector[2];
	outputVector[1] = invMatrix[1][0] * inputVector[0] + invMatrix[1][1] * inputVector[1] + invMatrix[1][2] * inputVector[2];
	outputVector[2] = invMatrix[2][0] * inputVector[0] + invMatrix[2][1] * inputVector[1] + invMatrix[2][2] * inputVector[2];
}

template <typename Real>
typename const Mathematics::LinearSystem<Real>::VariableMatrixType	Mathematics::LinearSystem<Real>
	::Inverse(const VariableMatrixType& matrix) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "��������Ƿ���\n");

	LinearSystemInverse<Real> inverse{ matrix, m_ZeroTolerance };

	return inverse.GetInverse();
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (inputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("inputVectorָ��Ϊ�գ�"));
	}
	if (outputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputVectorָ��Ϊ�գ�"));
	}

	LinearSystemInverse<Real> inverse{ matrix, m_ZeroTolerance, inputVector };

	auto index = 0;
	for (auto iter = inverse.GetBegin(), end = inverse.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveTridiagonal(int size, const Real* lower, const Real* main1, const Real* upper, const Real* right, Real* output) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 < size, "����Ĵ�СΪ�������");
	if (lower == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("lowerָ��Ϊ�գ�"));
	}

	if (main1 == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("mainָ��Ϊ�գ�"));
	}

	if (upper == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("upperָ��Ϊ�գ�"));
	}

	if (right == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("rightָ��Ϊ�գ�"));
	}

	if (output == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputָ��Ϊ�գ�"));
	}

	if (Math::FAbs(main1[0]) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"));
	}

	auto upperAmendSize = size - 1;

	RealVector upperAmend(upperAmendSize);

	auto mainAmend = main1[0];

	output[0] = right[0] / mainAmend;

	for (auto i = 0; i < size - 1; ++i)
	{
		upperAmend[i] = upper[i] / mainAmend;
		mainAmend = main1[i + 1] - lower[i] * upperAmend[i];
		if (Math::FAbs(mainAmend) <= m_ZeroTolerance)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"));
		}

		output[i + 1] = (right[i + 1] - lower[i] * output[i]) / mainAmend;
	}

	for (auto i = size - 1; 1 <= i; --i)
	{
		auto temp = i - 1;
		output[temp] -= upperAmend[temp] * output[i];
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveConstTridiagonal(int size, Real lower, Real main1, Real upper, const Real* right, Real* output) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (right == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("rightָ��Ϊ�գ�"));
	}
	if (output == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputָ��Ϊ�գ�"));
	}

	if (Math::FAbs(main1) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"));
	}

	auto upperAmendSize = size - 1;
	RealVector upperAmend(upperAmendSize);
	auto mainAmend = main1;

	output[0] = right[0] / mainAmend;

	for (auto i = 0; i < size - 1; ++i)
	{
		upperAmend[i] = upper / mainAmend;
		mainAmend = main1 - lower * upperAmend[i];
		if (Math::FAbs(mainAmend) <= m_ZeroTolerance)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"));
		}

		output[i + 1] = (right[i + 1] - lower * output[i]) / mainAmend;
	}

	for (auto i = size - 1; 1 <= i; --i)
	{
		auto temp2 = i - 1;
		output[temp2] -= upperAmend[temp2] * output[i];
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveSymmetricConjugateGradient(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(inputVector != nullptr, "inputVectorָ��Ϊ�գ�");

	if (outputVector == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("outputVectorָ��Ϊ�գ�"));
	}

	// ������Golum��Van Loan�ġ�������㡱�㷨��
	MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "��������Ƿ���\n");

	Mathematics::SolveSymmetricConjugateGradient<Real, VariableMatrix> solve{ matrix,inputVector,m_ZeroTolerance };

	auto index = 0;
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveSymmetricConjugateGradient(const SparseMatrixType& matrix, const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	// ������Golum��Van Loan�ġ�������㡱�㷨��
	MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "��������Ƿ���\n");

	Mathematics::SolveSymmetricConjugateGradient<Real, SparseMatrix> solve{ matrix,inputVector,m_ZeroTolerance };

	auto index = 0;
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveBanded(const BandedMatrix& matrix, const Real* inputVector, Real* outputVector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Mathematics::SolveBanded<Real>	solve{ matrix, inputVector, m_ZeroTolerance };

	auto index = 0;
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
typename const Mathematics::LinearSystem<Real>::VariableMatrixType Mathematics::LinearSystem<Real>
	::Invert(const BandedMatrix& matrix) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Mathematics::BandedMatrixInvert<Real> invert{ matrix, m_ZeroTolerance };

	return invert.GetInvert();
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H
