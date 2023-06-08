///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:38)

#include "Mathematics/MathematicsExport.h"

#include "SparseMatrixIndex.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <utility>

Mathematics::SparseMatrixIndex::SparseMatrixIndex(int row, int column) noexcept
    : row{ row }, column{ column }
{
    if (column < row)
    {
        std::swap(this->column, this->row);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Mathematics::SparseMatrixIndex ::IsValid() const noexcept
{
    if (0 <= row && row <= column)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Mathematics::SparseMatrixIndex::GetRow() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return row;
}

int Mathematics::SparseMatrixIndex::GetColumn() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return column;
}

bool Mathematics::operator<(const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs) noexcept
{
    if (lhs.GetRow() < rhs.GetRow())
        return true;
    else if (rhs.GetRow() < lhs.GetRow())
        return false;
    else
        return lhs.GetColumn() < rhs.GetColumn();
}
