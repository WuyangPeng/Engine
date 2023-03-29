///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 14:32)

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