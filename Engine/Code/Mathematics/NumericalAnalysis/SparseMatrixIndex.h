/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE SparseMatrixIndex final
    {
    public:
        using ClassType = SparseMatrixIndex;

    public:
        SparseMatrixIndex(int row, int column) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetRow() const noexcept;
        NODISCARD int GetColumn() const noexcept;

    private:
        int row;
        int column;
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs) noexcept;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
