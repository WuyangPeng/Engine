///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 14:32)

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
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0) noexcept(std::is_arithmetic_v<Type>)
    : tuple{ param0 }
{
    static_assert(Dimension == 1, "Dimension == 1");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1) noexcept(std::is_arithmetic_v<Type>)
    : tuple{ param0, param1 }
{
    static_assert(Dimension == 2, "Dimension == 2");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1, ParamType param2) noexcept(std::is_arithmetic_v<Type>)
    : tuple{ param0, param1, param2 }
{
    static_assert(Dimension == 3, "Dimension == 3");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>::Tuple(ParamType param0, ParamType param1, ParamType param2, ParamType param3) noexcept(std::is_arithmetic_v<Type>)
    : tuple{ param0, param1, param2, param3 }
{
    static_assert(Dimension == 4, "Dimension == 4");

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

    for (const auto& value : tuple)
    {
        sum += value;
    }

    return sum;
}

// 非成员函数
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
    for (const auto& value : tuple)
    {
        os << value << " ";
    }

    return os;
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H