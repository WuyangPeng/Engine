// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 15:20)

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
	// 从“矩阵计算”实现其他QR分解和奇异值分解代码，然后给用户指定这里使用哪些方法的能力。    

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
	// 矩阵Real是A的副本，然后在算法中用正确项重写上三角。
	auto numRows = m_Diagonal.GetRowsNumber();
	auto numColumns = m_Diagonal.GetColumnsNumber();
	MATHEMATICS_ASSERTION_3(numColumns <= numRows, "太多的列（使用转置矩阵）\n");

	std::vector<VariableLengthVector> saveVector;
	for (auto column = 0; column < numColumns; ++column)
	{
		VariableLengthVector vector{ numRows };

		// 创建Householder向量对A的部分列
		for (auto row = 0; row < column; ++row)
		{
			vector[row] = Math<Real>::sm_Zero;
		}
		auto length = Math<Real>::sm_Zero;
		for (auto row = column; row < numRows; ++row)
		{
			vector[row] = m_Diagonal[row][column];
			length += vector[row] * vector[row];
		}
		length = Math<Real>::Sqrt(length);
		auto beta = vector[column] + Math<Real>::Sign(vector[column]) * length;
		if (Math<Real>::sm_ZeroTolerance < Math<Real>::FAbs(beta))
		{
			for (int i = column + 1; i < numRows; ++i)
			{
				vector[i] /= beta;
			}
		}
		vector[column] = static_cast<Real>(1);

		// 由V-反射矩阵预乘A。
		HouseholderPremultiply(vector, m_Diagonal);

		// 保存Householder向量
		saveVector.push_back(vector);
	}

	// 首先，使Q为identity。第二，提取Householder向量和以V-反射矩阵预乘Q。
	m_Left.SetIdentity();

	for (auto column = numColumns - 1; 0 <= column; --column)
	{
		// 获取Householder向量
		auto vector = saveVector[column];

		// 由V-反射矩阵预乘Q。
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
	if (Math<Real>::sm_ZeroTolerance < Math<Real>::FAbs(beta))
	{
		for (auto i = 1; i < householderVector.GetSize(); ++i)
		{
			householderVector[i] /= beta;
		}
	}

	householderVector[0] = static_cast<Real>(1);

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
