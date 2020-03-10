// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:16)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H

#include "TupleLess.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

template <int Dimension, typename Type>
CoreTools::TupleLess<Dimension, Type>
	::TupleLess(int index)
	:m_Index{ index }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <int Dimension, typename Type>
bool CoreTools::TupleLess<Dimension, Type>
	::IsValid() const noexcept
{
	if (0 <= m_Index && m_Index < Dimension)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
bool CoreTools::TupleLess<Dimension, Type>
	::operator()(const Tuple& lhs, const Tuple& rhs) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return lhs[m_Index] < rhs[m_Index];
}

#endif // CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H