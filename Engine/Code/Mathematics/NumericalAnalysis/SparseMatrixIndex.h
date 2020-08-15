// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE SparseMatrixIndex
	{
	public:
		using ClassType = SparseMatrixIndex;

	public:
		SparseMatrixIndex(int row, int column) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetRow() const noexcept; 
		int GetColumn() const noexcept;

	private:
		int m_Row;
		int m_Column;
	};

	bool MATHEMATICS_DEFAULT_DECLARE operator < (const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs) noexcept;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
