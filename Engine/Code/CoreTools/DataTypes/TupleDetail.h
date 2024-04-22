/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:46)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H

#include "Tuple.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple() noexcept
    : tuple{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0) noexcept(std::is_arithmetic_v<Type>) requires(Dimension == 1)
    : tuple{ param0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1) noexcept(std::is_arithmetic_v<Type>) requires(Dimension == 2)
    : tuple{ param0, param1 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1, ParamType param2) noexcept(std::is_arithmetic_v<Type>) requires(Dimension == 3)
    : tuple{ param0, param1, param2 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1, ParamType param2, ParamType param3) noexcept(std::is_arithmetic_v<Type>) requires(Dimension == 4)
    : tuple{ param0, param1, param2, param3 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
bool CoreTools::Tuple<Dimension, Type>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
const Type& CoreTools::Tuple<Dimension, Type>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return tuple.at(index);
}

template <int Dimension, typename Type>
Type& CoreTools::Tuple<Dimension, Type>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Type, index);
}

template <int Dimension, typename Type>
typename CoreTools::Tuple<Dimension, Type>::ArrayTypeConstIter CoreTools::Tuple<Dimension, Type>::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return tuple.begin();
}

template <int Dimension, typename Type>
typename CoreTools::Tuple<Dimension, Type>::ArrayTypeConstIter CoreTools::Tuple<Dimension, Type>::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return tuple.end();
}

template <int Dimension, typename Type>
Type CoreTools::Tuple<Dimension, Type>::GetSum() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Type sum{};

    for (const auto& element : tuple)
    {
        sum += element;
    }

    return sum;
}

template <int Dimension, typename Type>
bool CoreTools::operator==(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <int Dimension, typename Type>
bool CoreTools::operator<(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <int Dimension, typename Type>
std::ostream& CoreTools::operator<<(std::ostream& os, const Tuple<Dimension, Type>& tuple)
{
    for (const auto& element : tuple)
    {
        os << element << " ";
    }

    return os;
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H