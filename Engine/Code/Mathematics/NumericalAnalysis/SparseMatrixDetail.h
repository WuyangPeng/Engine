// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 17:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H

#include "SparseMatrix.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

template <typename Real>
Mathematics::SparseMatrix<Real>
	::SparseMatrix(int rowsNumber, int columnsNumber)
	:m_RowsNumber{ rowsNumber }, m_ColumnsNumber{ columnsNumber }, m_SparseMatrixEntry{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SparseMatrix<Real>
	::IsValid() const  noexcept
{
	if (0 < m_RowsNumber && 0 < m_ColumnsNumber)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::SparseMatrix<Real>
	::GetRowsNumber() const  noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RowsNumber;
}

template <typename Real>
int Mathematics::SparseMatrix<Real>
	::GetColumnsNumber() const  noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ColumnsNumber;
}

template <typename Real>
const Real& Mathematics::SparseMatrix<Real>
	::operator()(int row, int column) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "rowÀ˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= column && column < m_ColumnsNumber, "columnÀ˜“˝¥ÌŒÛ£°");

	auto iter = m_SparseMatrixEntry.find(SparseMatrixIndex(row, column));

	if (iter != m_SparseMatrixEntry.end())
	{
		return iter->second;
	}
	else
	{
		return sm_Zero;
	}
}

template <typename Real>
Real& Mathematics::SparseMatrix<Real>
	::operator()(int row, int column)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "rowÀ˜“˝¥ÌŒÛ£°");
	MATHEMATICS_ASSERTION_0(0 <= column && column < m_ColumnsNumber, "columnÀ˜“˝¥ÌŒÛ£°");

	return m_SparseMatrixEntry[SparseMatrixIndex(row, column)];
}


template <typename Real>
typename const Mathematics::SparseMatrix<Real>::ConstIter Mathematics::SparseMatrix<Real>
	::GetBegin() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ConstIter{ m_SparseMatrixEntry.begin() };
}

template <typename Real>
typename const Mathematics::SparseMatrix<Real>::ConstIter Mathematics::SparseMatrix<Real>
	::GetEnd() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ConstIter{ m_SparseMatrixEntry.end() };
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics
	::operator*(const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
	VariableLengthVector<Real> result{ vector.GetSize() };

	for (auto iter = matrix.GetBegin(), end = matrix.GetEnd(); iter != end; ++iter)
	{
		auto row = iter.GetKey().GetRow();
		auto column = iter.GetKey().GetColumn();
		auto value = iter.GetMapped();
		result[row] += value * vector[column];
		if (row != column)
		{
			result[column] += value * vector[row];
		}
	}

	return result;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H
