/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:43)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H

#include "TupleLess.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <int Dimension, typename Type>
CoreTools::TupleLess<Dimension, Type>::TupleLess(int index) noexcept
    : index{ index }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
bool CoreTools::TupleLess<Dimension, Type>::IsValid() const noexcept
{
    if (0 <= index && index < Dimension)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
bool CoreTools::TupleLess<Dimension, Type>::operator()(const Tuple& lhs, const Tuple& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return lhs[index] < rhs[index];
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_LESS_DETAIL_H