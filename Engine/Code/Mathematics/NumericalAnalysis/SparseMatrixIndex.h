///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 10:04)

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

        [[nodiscard]] int GetRow() const noexcept;
        [[nodiscard]] int GetColumn() const noexcept;

    private:
        int m_Row;
        int m_Column;
    };

    [[nodiscard]] bool MATHEMATICS_DEFAULT_DECLARE operator<(const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs) noexcept;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_INDEX_H
