// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrixIndex.h"
#include "SparseMatrixConstIteratorDetail.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <map>

namespace Mathematics
{
	template <typename Real>
	class SparseMatrix
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = SparseMatrix<Real>;
		using ConstIter = SparseMatrixConstIterator<Real>;

	public:
		SparseMatrix(int rowsNumber, int columnsNumber);

		CLASS_INVARIANT_DECLARE;

		int GetRowsNumber() const noexcept;
		int GetColumnsNumber() const noexcept;

		const Real& operator() (int row, int column) const;
		Real& operator() (int row, int column);

		const ConstIter GetBegin() const;
		const ConstIter GetEnd() const;

	private:
		using SparseMatrixEntry = std::map<SparseMatrixIndex, Real>; 

	private:
		static constexpr Real sm_Zero{};

		int m_RowsNumber;
		int m_ColumnsNumber;
		SparseMatrixEntry m_SparseMatrixEntry;
	};

	// M * v (numColumns(matrix) = size(vector) �Ǳ����)
	template <typename Real>
	const VariableLengthVector<Real> operator* (const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

	using SparseMatrixf = SparseMatrix<float>;
	using SparseMatrixd = SparseMatrix<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
