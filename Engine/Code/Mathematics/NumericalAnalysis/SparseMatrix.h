// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/09 10:53)

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
		using SparseMatrixEntryConstIter = typename SparseMatrixEntry::const_iterator;
		using SparseMatrixEntryIter = typename SparseMatrixEntry::iterator;

	private:
		static constexpr Real sm_Zero{};

		int m_RowsNumber;
		int m_ColumnsNumber;
		SparseMatrixEntry m_SparseMatrixEntry;
    };

	// M * v (numColumns(matrix) = size(vector) 是必须的)
	template <typename Real>
	const VariableLengthVector<Real> operator* (const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    using SparseMatrixf = SparseMatrix<float>;
	using SparseMatrixd = SparseMatrix<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
