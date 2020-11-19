// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 14:23)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H

#include "EigenDecomposition.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::EigenDecomposition(int size)
	:m_Size{ size }, m_Matrix{ m_Size, m_Size }, m_SolveMatrix{ m_Size, m_Size }, m_Diagonal(m_Size),
	 m_Subdiagonal(m_Size), m_IsRotation{ false }, m_Solve{ false }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::EigenDecomposition(const Matrix2& rhs)
	:m_Size{ 2 }, m_Matrix{ rhs }, m_SolveMatrix{ rhs }, m_Diagonal(m_Size),
	 m_Subdiagonal(m_Size), m_IsRotation{ false }, m_Solve{ false }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::EigenDecomposition(const Matrix3& rhs)
	:m_Size{ 3 }, m_Matrix{ rhs }, m_SolveMatrix{ rhs }, m_Diagonal(m_Size),
	 m_Subdiagonal(m_Size), m_IsRotation{ false }, m_Solve{ false }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::EigenDecomposition(const VariableMatrix& rhs)
	:m_Size{ rhs.GetRowsNumber() }, m_Matrix{ rhs }, m_SolveMatrix{ rhs }, m_Diagonal(m_Size),
	 m_Subdiagonal(m_Size), m_IsRotation{ false }, m_Solve{ false }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::EigenDecomposition(const EigenDecomposition& rhs)
	:m_Size{ rhs.m_Size }, m_Matrix{ rhs.m_Matrix }, m_SolveMatrix{ rhs.m_SolveMatrix }, m_Diagonal{ rhs.m_Diagonal },
	 m_Subdiagonal{ rhs.m_Subdiagonal }, m_IsRotation{ rhs.m_IsRotation }, m_Solve{ rhs.m_Solve }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>
	::~EigenDecomposition()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>
	::operator= (const EigenDecomposition& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	EigenDecomposition result{ rhs };

	Swap(result);

	return *this;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::Swap(EigenDecomposition& rhs)
{
	std::swap(m_Size, rhs.m_Size);
	m_Matrix.Swap(rhs.m_Matrix);
	m_SolveMatrix.Swap(rhs.m_SolveMatrix);
	m_Diagonal.swap(rhs.m_Diagonal);
	m_Subdiagonal.swap(rhs.m_Subdiagonal);
	std::swap(m_IsRotation, rhs.m_IsRotation);
	std::swap(m_Solve, rhs.m_Solve);
}

template <typename Real>
Mathematics::EigenDecomposition<Real>&	Mathematics::EigenDecomposition<Real>
	::operator= (const Matrix2& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	EigenDecomposition result{ rhs };

	Swap(result);

	return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>&	Mathematics::EigenDecomposition<Real>
	::operator= (const Matrix3& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	EigenDecomposition result{ rhs };

	Swap(result);

	return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>
	::operator= (const VariableMatrix& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	EigenDecomposition result{ rhs };

	Swap(result);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EigenDecomposition<Real>
	::IsValid() const noexcept
{
	if (2 <= m_Size && m_Matrix.GetColumnsNumber() == m_Matrix.GetRowsNumber() &&
		m_SolveMatrix.GetColumnsNumber() == m_SolveMatrix.GetRowsNumber() &&
		m_Matrix.GetColumnsNumber() == m_SolveMatrix.GetColumnsNumber())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::EigenDecomposition<Real>
	::GetSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Size;
}

template <typename Real>
const Real& Mathematics::EigenDecomposition<Real>
	::operator() (int row, int column) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "��������");

	return m_Matrix(row, column);
}

template <typename Real>
Real& Mathematics::EigenDecomposition<Real>
	::operator() (int row, int column)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "��������");

	return const_cast<Real&>(static_cast<const EigenDecomposition&>(*this)(row, column));
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::Solve(bool increasingSort)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Solve = false;

	switch (m_Size)
	{
	case 2:
		Tridiagonal2();
		break;
	case 3:
		Tridiagonal3();
		break;
	default:
		TridiagonalN();
		break;
	}

	QLAlgorithm();

	if (increasingSort)
	{
		IncreasingSort();
	}
	else
	{
		DecreasingSort();
	}

	GuaranteeRotation();

	m_Solve = true;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::Tridiagonal2()
{
	// �þ������Ѿ������ԽǾ���
	m_Diagonal[0] = m_Matrix[0][0];
	m_Diagonal[1] = m_Matrix[1][1];
	m_Subdiagonal[0] = m_Matrix[0][1];
	m_Subdiagonal[1] = Math::GetValue(0);
	m_SolveMatrix[0][0] = Math::GetValue(1);
	m_SolveMatrix[0][1] = Math::GetValue(0);
	m_SolveMatrix[1][0] = Math::GetValue(0);
	m_SolveMatrix[1][1] = Math::GetValue(1);

	m_IsRotation = true;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
::Tridiagonal3()
{
	auto m00 = m_Matrix[0][0];
	auto m01 = m_Matrix[0][1];
	auto m02 = m_Matrix[0][2];
	auto m11 = m_Matrix[1][1];
	auto m12 = m_Matrix[1][2];
	auto m22 = m_Matrix[2][2];

	m_Diagonal[0] = m00;
	m_Subdiagonal[2] = Math::GetValue(0);
	if (Math::GetZeroTolerance() < Math::FAbs(m02))
	{
		auto length = Math::Sqrt(m01 * m01 + m02 * m02);
		m01 /= length;
		m02 /= length;
		Real q = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
		m_Diagonal[1] = m11 + m02 * q;
		m_Diagonal[2] = m22 - m02 * q;
		m_Subdiagonal[0] = length;
		m_Subdiagonal[1] = m12 - m01 * q;
		m_SolveMatrix[0][0] = Math::GetValue(1);
		m_SolveMatrix[0][1] = Math::GetValue(0);
		m_SolveMatrix[0][2] = Math::GetValue(0);
		m_SolveMatrix[1][0] = Math::GetValue(0);
		m_SolveMatrix[1][1] = m01;
		m_SolveMatrix[1][2] = m02;
		m_SolveMatrix[2][0] = Math::GetValue(0);
		m_SolveMatrix[2][1] = m02;
		m_SolveMatrix[2][2] = -m01;

		m_IsRotation = false;
	}
	else
	{
		m_Diagonal[1] = m11;
		m_Diagonal[2] = m22;
		m_Subdiagonal[0] = m01;
		m_Subdiagonal[1] = m12;
		m_SolveMatrix[0][0] = Math::GetValue(1);
		m_SolveMatrix[0][1] = Math::GetValue(0);
		m_SolveMatrix[0][2] = Math::GetValue(0);
		m_SolveMatrix[1][0] = Math::GetValue(0);
		m_SolveMatrix[1][1] = Math::GetValue(1);
		m_SolveMatrix[1][2] = Math::GetValue(0);
		m_SolveMatrix[2][0] = Math::GetValue(0);
		m_SolveMatrix[2][1] = Math::GetValue(0);
		m_SolveMatrix[2][2] = Math::GetValue(1);

		m_IsRotation = true;
	}
}
// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::TridiagonalN()
{
	m_SolveMatrix = m_Matrix;

	FirstStep();
	SecondStep();
	ThirdStep();

	m_IsRotation = ((m_Size % 2) == 0);
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::FirstStep()
{
	for (auto index = m_Size - 1; 1 <= index; --index)
	{
		if (1 < index)
		{
			TridiagonalNInLoop(index);
		}
		else
		{
			m_Subdiagonal[index] = m_SolveMatrix[index][index - 1];
			m_Diagonal[index] = Math::GetValue(0);
		}
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::TridiagonalNInLoop(int index)
{
	auto scale = GetScale(index);

	if (Math::FAbs(scale) <= Math::GetZeroTolerance())
	{
		m_Subdiagonal[index] = m_SolveMatrix[index][index - 1];
		m_Diagonal[index] = Math::GetValue(0);
	}
	else
	{
		CalculateDiagonal(index, scale);
		CalculateSubdiagonal(index);
	}
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::CalculateDiagonal(int index, Real scale)
{
	Real diagonaValue = Math::GetValue(0);

	for (auto diagonaIndex = 0; diagonaIndex <= index - 1; ++diagonaIndex)
	{
		m_SolveMatrix[index][diagonaIndex] /= scale;
		diagonaValue += m_SolveMatrix[index][diagonaIndex] * m_SolveMatrix[index][diagonaIndex];
	}

	auto solveMatrixValue = m_SolveMatrix[index][index - 1];
	auto diagonaValueSqrt = Math::Sqrt(diagonaValue);
	if (Math::GetValue(0) < solveMatrixValue)
	{
		diagonaValueSqrt = -diagonaValueSqrt;
	}

	m_Subdiagonal[index] = scale * diagonaValueSqrt;
	diagonaValue -= solveMatrixValue * diagonaValueSqrt;
	m_SolveMatrix[index][index - 1] = solveMatrixValue - diagonaValueSqrt;

	m_Diagonal[index] = diagonaValue;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::CalculateSubdiagonal(int index)
{
	auto diagonaValue = m_Diagonal[index];
	Real subdiagonalProduct = Math::GetValue(0);

	for (int outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
	{
		m_SolveMatrix[outerIndex][index] = m_SolveMatrix[index][outerIndex] / diagonaValue;
		Real solveMatrixProduct = Math::GetValue(0);
		for (int innerIndex = 0; innerIndex <= outerIndex; ++innerIndex)
		{
			solveMatrixProduct += m_SolveMatrix[outerIndex][innerIndex] * m_SolveMatrix[index][innerIndex];
		}

		for (auto innerIndex = outerIndex + 1; innerIndex <= index - 1; ++innerIndex)
		{
			solveMatrixProduct += m_SolveMatrix[innerIndex][outerIndex] * m_SolveMatrix[index][innerIndex];
		}

		m_Subdiagonal[outerIndex] = solveMatrixProduct / diagonaValue;
		subdiagonalProduct += m_Subdiagonal[outerIndex] * m_SolveMatrix[index][outerIndex];
	}

	auto value =  Math::GetRational(1,2) * subdiagonalProduct / diagonaValue;
	for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
	{
		auto solveMatrixValue = m_SolveMatrix[index][outerIndex];
		auto subdiagonalValue = m_Subdiagonal[outerIndex] - value * solveMatrixValue;
		m_Subdiagonal[outerIndex] = subdiagonalValue;
		for (int innerIndex = 0; innerIndex <= outerIndex; innerIndex++)
		{
			m_SolveMatrix[outerIndex][innerIndex] -= solveMatrixValue * m_Subdiagonal[innerIndex] + subdiagonalValue * m_SolveMatrix[index][innerIndex];
		}
	}
}

// private
template <typename Real>
Real Mathematics::EigenDecomposition<Real>
	::GetScale(int index) const
{
	auto scale = Math::GetValue(0);

	for (auto scaleIndex = 0; scaleIndex <= index - 1; ++scaleIndex)
	{
		scale += Math::FAbs(m_SolveMatrix[index][scaleIndex]);
	}

	return scale;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::SecondStep()
{
	m_Diagonal[0] = Math::GetValue(0);
	m_Subdiagonal[0] = Math::GetValue(0);
	for (auto index = 0; index <= m_Size - 1; ++index)
	{
		if (Math::GetZeroTolerance() < Math::FAbs(m_Diagonal[index]))
		{
			for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
			{
				Real sum{ };
				for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
				{
					sum += m_SolveMatrix[index][innerIndex] * m_SolveMatrix[innerIndex][outerIndex];
				}
				for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
				{
					m_SolveMatrix[innerIndex][outerIndex] -= sum * m_SolveMatrix[innerIndex][index];
				}
			}
		}
		m_Diagonal[index] = m_SolveMatrix[index][index];
		m_SolveMatrix[index][index] = Math::GetValue(1);
		for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
		{
			m_SolveMatrix[innerIndex][index] = Math::GetValue(0);
			m_SolveMatrix[index][innerIndex] = Math::GetValue(0);
		}
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::ThirdStep()
{
	// ����������Ҫ��EigenDecomposition::QLAlgorithm��
	for (auto index = 1; index < m_Size; ++index)
	{
		auto temp = index - 1;
		m_Subdiagonal[temp] = m_Subdiagonal[index];
	}
	auto temp1 = m_Size - 1;
	m_Subdiagonal[temp1] = Math::GetValue(0);
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::QLAlgorithm()
{
	for (auto index = 0; index < m_Size; ++index)
	{
		QLAlgorithm(index);
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::QLAlgorithm(int index)
{
	auto loopTime = QLAlgorithmWithLoopTime(index);

	if (sm_MaxIter <= loopTime)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ѭ������������"));
	}
}

template <typename Real>
int Mathematics::EigenDecomposition<Real>
	::QLAlgorithmWithLoopTime(int totalIndex)
{
	for (auto loopTime = 0; loopTime < sm_MaxIter; ++loopTime)
	{
		auto outerIndex = totalIndex;
		for (; outerIndex <= m_Size - 2; ++outerIndex)
		{
			if (IsQLAlgorithmQuit(outerIndex))
			{
				break;
			}
		}
		if (outerIndex == totalIndex)
		{
			return loopTime;
		}

		QLAlgorithmLoop(totalIndex, outerIndex);
	}

	return sm_MaxIter;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::QLAlgorithmLoop(int totalIndex, int outerIndex)
{
	auto subdiagonalValue = GetQLAlgorithmSubdiagonalValue(totalIndex, outerIndex);
	auto sine = Math::GetValue(1);
	auto cosine = Math::GetValue(1);
	auto diagonalDifferenceValue = Math::GetValue(0);

	for (auto innerIndex = outerIndex - 1; innerIndex >= totalIndex; --innerIndex)
	{
		auto subdiagonalSineValue = sine * m_Subdiagonal[innerIndex];
		auto subdiagonalCosineValue = cosine * m_Subdiagonal[innerIndex];

		if (Math::FAbs(subdiagonalValue) <= Math::FAbs(subdiagonalSineValue))
		{
			cosine = subdiagonalValue / subdiagonalSineValue;
			auto cosineAmend = Math::Sqrt(cosine * cosine + Math::GetValue(1));
			auto temp = innerIndex + 1;
			m_Subdiagonal[temp] = subdiagonalSineValue * cosineAmend;
			sine = Math::GetValue(1) / cosineAmend;
			cosine *= sine;
		}
		else
		{
			sine = subdiagonalSineValue / subdiagonalValue;
			auto cosineAmend = Math::Sqrt(sine * sine + Math::GetValue(1));
			auto temp = innerIndex + 1;
			m_Subdiagonal[temp] = subdiagonalValue * cosineAmend;
			cosine = Math::GetValue(1) / cosineAmend;
			sine *= cosine;
		}
		auto temp = innerIndex + 1;
		subdiagonalValue = m_Diagonal[temp] - diagonalDifferenceValue;
		auto value = (m_Diagonal[innerIndex] - subdiagonalValue) * sine + Math::GetValue(2) * subdiagonalCosineValue * cosine;
		diagonalDifferenceValue = sine * value;
		m_Diagonal[temp] = subdiagonalValue + diagonalDifferenceValue;
		subdiagonalValue = cosine * value - subdiagonalCosineValue;

		QLAlgorithmAmendSolveMatrix(innerIndex, sine, cosine);
	}

	m_Diagonal[totalIndex] -= diagonalDifferenceValue;
	m_Subdiagonal[totalIndex] = subdiagonalValue;
	m_Subdiagonal[outerIndex] = Math::GetValue(0);
}

// private
template <typename Real>
Real Mathematics::EigenDecomposition<Real>
	::GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const
{
	auto temp = totalIndex + 1;
	auto value = (m_Diagonal[temp] - m_Diagonal[totalIndex]) / (Math::GetValue(2) * m_Subdiagonal[totalIndex]);

	auto amendValue = Math::Sqrt(value * value + Math::GetValue(1));
	if (value < Math::GetValue(0))
	{
		return m_Diagonal[outerIndex] - m_Diagonal[totalIndex] + m_Subdiagonal[totalIndex] / (value - amendValue);
	}
	else
	{
		return m_Diagonal[outerIndex] - m_Diagonal[totalIndex] + m_Subdiagonal[totalIndex] / (value + amendValue);
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine)
{
	for (auto i = 0; i < m_Size; ++i)
	{
		auto value = m_SolveMatrix[i][innerIndex + 1];

		m_SolveMatrix[i][innerIndex + 1] = sine * m_SolveMatrix[i][innerIndex] + cosine * value;
		m_SolveMatrix[i][innerIndex] = cosine * m_SolveMatrix[i][innerIndex] - sine * value;
	}
}

// private
template <typename Real>
bool Mathematics::EigenDecomposition<Real>
	::IsQLAlgorithmQuit(int outerIndex) const
{
	auto temp = outerIndex + 1;
	auto diagonalSum = Math::FAbs(m_Diagonal[outerIndex]) + Math::FAbs(m_Diagonal[temp]);

	if (Math::FAbs(Math::FAbs(m_Subdiagonal[outerIndex]) + diagonalSum - diagonalSum) <= Math::GetZeroTolerance())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::DecreasingSort()
{
	// ��������ֵ���ݼ�˳��e[0] >= ... >= e[mSize-1]
	for (auto outerIndex = 0; outerIndex <= m_Size - 2; ++outerIndex)
	{
		// �ҵ��������ֵ��
		auto minIndex = outerIndex;
		auto maxValue = m_Diagonal[minIndex];

		for (auto innerIndex = outerIndex + 1; innerIndex < m_Size; ++innerIndex)
		{
			if (maxValue < m_Diagonal[innerIndex])
			{
				minIndex = innerIndex;
				maxValue = m_Diagonal[minIndex];
			}
		}

		if (minIndex != outerIndex)
		{
			// ����������ֵ��
			m_Diagonal[minIndex] = m_Diagonal[outerIndex];
			m_Diagonal[outerIndex] = maxValue;

			// ������Ӧ������ֵ������������
			for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
			{
				std::swap(m_SolveMatrix[innerIndex][outerIndex], m_SolveMatrix[innerIndex][minIndex]);

				m_IsRotation = !m_IsRotation;
			}
		}
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::IncreasingSort()
{
	// ��������ֵ������˳�� e[0] <= ... <= e[mSize-1]
	for (auto outerIndex = 0; outerIndex <= m_Size - 2; ++outerIndex)
	{
		// �ҵ���С����ֵ��
		auto minIndex = outerIndex;
		auto minValue = m_Diagonal[minIndex];

		for (auto innerIndex = outerIndex + 1; innerIndex < m_Size; ++innerIndex)
		{
			if (m_Diagonal[innerIndex] < minValue)
			{
				minIndex = innerIndex;
				minValue = m_Diagonal[minIndex];
			}
		}

		if (minIndex != outerIndex)
		{
			// ��������ֵ��
			m_Diagonal[minIndex] = m_Diagonal[outerIndex];
			m_Diagonal[outerIndex] = minValue;

			// ������Ӧ������ֵ������������
			for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
			{
				std::swap(m_SolveMatrix[innerIndex][outerIndex], m_SolveMatrix[innerIndex][minIndex]);

				m_IsRotation = !m_IsRotation;
			}
		}
	}
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>
	::GuaranteeRotation()
{
	if (!m_IsRotation)
	{
		// �ı�����ڵ�һ���С�
		for (auto row = 0; row < m_Size; ++row)
		{
			m_SolveMatrix[row][0] = -m_SolveMatrix[row][0];
		}
	}
}

template <typename Real>
Real Mathematics::EigenDecomposition<Real>
	::GetEigenvalue(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��Ч������GetEigenvalue\n");

	return m_Diagonal[index];
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::Vector2D Mathematics::EigenDecomposition<Real>
	::GetEigenvector2(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��Ч������GetEigenvector2\n");
	MATHEMATICS_ASSERTION_1(m_Size == 2, "ά�Ȳ�ƥ����GetEigenvector2\n");

	Vector2D eigenvector;
	for (auto row = 0; row < m_Size; ++row)
	{
		eigenvector[row] = m_SolveMatrix[row][index];
	}

	return eigenvector;
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::Matrix2 Mathematics::EigenDecomposition<Real>
	::GetEigenvectors2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_1(m_Size == 2, "ά�Ȳ�ƥ����GetEigenvector2\n");

	Matrix2 eigenvectors;
	for (auto row = 0; row < 2; ++row)
	{
		for (auto column = 0; column < 2; ++column)
		{
			eigenvectors(row, column) = m_SolveMatrix[row][column];
		}
	}

	return eigenvectors;
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::Vector3D Mathematics::EigenDecomposition<Real>
	::GetEigenvector3(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��Ч������GetEigenvector3\n");
	MATHEMATICS_ASSERTION_1(m_Size == 3, "ά�Ȳ�ƥ����GetEigenvector3\n");

	Vector3D eigenvector;
	for (auto row = 0; row < m_Size; ++row)
	{
		eigenvector[row] = m_SolveMatrix[row][index];
	}

	return eigenvector;
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::Matrix3 Mathematics::EigenDecomposition<Real>
	::GetEigenvectors3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_1(m_Size == 3, "ά�Ȳ�ƥ����GetEigenvector3\n");

	return m_SolveMatrix.GetMatrix3();
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::VariableLengthVector Mathematics::EigenDecomposition<Real>
	::GetEigenvector(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��Ч������GetEigenvector3\n");

	return m_SolveMatrix.GetColumn(index);
}

template <typename Real>
typename const Mathematics::EigenDecomposition<Real>::VariableMatrix Mathematics::EigenDecomposition<Real>
	::GetEigenvectors() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_Solve, "δ������");

	return m_SolveMatrix;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
