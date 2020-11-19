// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 15:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H

#include "SingularValueDecomposition.h"
#include "EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::SingularValueDecomposition<Real>
	::SingularValueDecomposition(const VariableMatrix& matrix)
	:m_Left{ matrix.GetRowsNumber(), matrix.GetRowsNumber() },
	 m_Diagonal{ matrix.GetRowsNumber(),matrix.GetColumnsNumber() },
	 m_RightTranspose{ matrix.GetColumnsNumber(),matrix.GetColumnsNumber() }
{
	Calculate(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void  Mathematics::SingularValueDecomposition<Real>
	::Calculate(const VariableMatrix& matrix)
{
	// �ӡ�������㡱ʵ������QR�ֽ������ֵ�ֽ���룬Ȼ����û�ָ������ʹ����Щ������������    

	auto transposeTimesMatrix = TransposeTimes(matrix, matrix);
	EigenDecomposition<Real> eigenDecomposition{ transposeTimesMatrix };
	eigenDecomposition.Solve(false);
	auto eigenvectors = eigenDecomposition.GetEigenvectors();

	m_Diagonal = matrix * eigenvectors;
	HouseholderQR();
	m_RightTranspose = eigenvectors.Transpose();
}

template <typename Real>
void Mathematics::SingularValueDecomposition<Real>
	::HouseholderQR()
{
	// ����Real��A�ĸ�����Ȼ�����㷨������ȷ����д�����ǡ�
	auto numRows = m_Diagonal.GetRowsNumber();
	auto numColumns = m_Diagonal.GetColumnsNumber();
	MATHEMATICS_ASSERTION_3(numColumns <= numRows, "̫����У�ʹ��ת�þ���\n");

	std::vector<VariableLengthVector> saveVector;
	for (auto column = 0; column < numColumns; ++column)
	{
		VariableLengthVector vector{ numRows };

		// ����Householder������A�Ĳ�����
		for (auto row = 0; row < column; ++row)
		{
			vector[row] = Math<Real>::GetValue(0);
		}
		auto length = Math<Real>::GetValue(0);
		for (auto row = column; row < numRows; ++row)
		{
			vector[row] = m_Diagonal[row][column];
			length += vector[row] * vector[row];
		}
		length = Math<Real>::Sqrt(length);
		auto beta = vector[column] + Math<Real>::Sign(vector[column]) * length;
		if (Math<Real>::GetZeroTolerance() < Math<Real>::FAbs(beta))
		{
			for (int i = column + 1; i < numRows; ++i)
			{
				vector[i] /= beta;
			}
		}
		vector[column] = Math::GetValue(1);

		// ��V-�������Ԥ��A��
		HouseholderPremultiply(vector, m_Diagonal);

		// ����Householder����
		saveVector.push_back(vector);
	}

	// ���ȣ�ʹQΪidentity���ڶ�����ȡHouseholder��������V-�������Ԥ��Q��
	m_Left.SetIdentity();

	for (auto column = numColumns - 1; 0 <= column; --column)
	{
		// ��ȡHouseholder����
		auto vector = saveVector[column];

		// ��V-�������Ԥ��Q��
		HouseholderPremultiply(vector, m_Left);
	}
}

// static
template <typename Real>
typename const Mathematics::SingularValueDecomposition<Real>::VariableLengthVector	Mathematics::SingularValueDecomposition<Real>
	::HouseholderVector(const VariableLengthVector& vector)
{
	auto householderVector = vector;
	auto length = householderVector.Length();
	auto beta = vector[0] + Math<Real>::Sign(vector[0]) * length;
	if (Math<Real>::GetZeroTolerance() < Math<Real>::FAbs(beta))
	{
		for (auto i = 1; i < householderVector.GetSize(); ++i)
		{
			householderVector[i] /= beta;
		}
	}

	householderVector[0] = Math::GetValue(1);

	return householderVector;
}

// static
template <typename Real>
void Mathematics::SingularValueDecomposition<Real>
	::HouseholderPremultiply(const VariableLengthVector& vector, VariableMatrix& matrix)
{
	auto transitionVector = vector * matrix;
	auto wVector = (static_cast<Real>(-2) / vector.SquaredLength()) * transitionVector;
	auto numRows = matrix.GetRowsNumber();
	auto numColumns = matrix.GetColumnsNumber();
	for (auto row = 0; row < numRows; ++row)
	{
		for (auto col = 0; col < numColumns; ++col)
		{
			matrix[row][col] += vector[row] * wVector[col];
		}
	}
}

// static
template <typename Real>
void Mathematics::SingularValueDecomposition<Real>
	::HouseholderPostmultiply(const VariableLengthVector& vector, VariableMatrix& matrix)
{
	auto transitionVector = (static_cast<Real>(-2) / vector.SquaredLength()) * (matrix * vector);
	auto numRows = matrix.GetRowsNumber();
	auto numColumns = matrix.GetColumnsNumber();
	for (auto row = 0; row < numRows; ++row)
	{
		for (auto col = 0; col < numColumns; ++col)
		{
			(matrix)[row][col] += transitionVector[row] * vector[col];
		}
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SingularValueDecomposition<Real>
	::IsValid() const noexcept
{
	if (m_Diagonal.GetColumnsNumber() <= m_Diagonal.GetRowsNumber())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>
	::GetLeftMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Left;
}

template <typename Real>
typename const Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>
	::GetDiagonalMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Diagonal;
}

template <typename Real>
typename const Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>
	::GetRightTransposeMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RightTranspose;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
