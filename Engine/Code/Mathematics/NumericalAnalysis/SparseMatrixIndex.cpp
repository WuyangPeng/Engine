// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.5 (2020/03/20 13:04)

#include "Mathematics/MathematicsExport.h"

#include "SparseMatrixIndex.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <utility>

Mathematics::SparseMatrixIndex
	::SparseMatrixIndex(int row, int column) noexcept
	:m_Row{ row }, m_Column{ column }
{
	if (m_Column < m_Row)
	{
		std::swap(m_Column, m_Row);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Mathematics::SparseMatrixIndex
	::IsValid() const noexcept
{
	if (0 <= m_Row && m_Row <= m_Column)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Mathematics::SparseMatrixIndex
	::GetRow() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Row;
}

int Mathematics::SparseMatrixIndex
	::GetColumn() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Column;
}

bool  Mathematics
	::operator<(const SparseMatrixIndex& lhs, const SparseMatrixIndex& rhs) noexcept
{
	if (lhs.GetRow() < rhs.GetRow())
		return true;
	else if (rhs.GetRow() < lhs.GetRow())
		return false;
	else
		return lhs.GetColumn() < rhs.GetColumn();
}
