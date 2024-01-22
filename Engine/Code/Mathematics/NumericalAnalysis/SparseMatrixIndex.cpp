/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:23)

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
