// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 10:56)

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
		SparseMatrixIndex(int row,int column);
        
		CLASS_INVARIANT_DECLARE;
        
		int GetRow() const;
		int GetColumn() const;

	private:
		int m_Row;
		int m_Column;
	};

	bool MATHEMATICS_DEFAULT_DECLARE operator < (const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs);
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
