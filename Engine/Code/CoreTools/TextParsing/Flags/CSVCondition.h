///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/25 19:19)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H

#include "System/Helper/UserMacro.h"

#include <iterator>
#include <string>
#include <type_traits>

namespace CoreTools::TextParsing
{
    template <typename T>
    constexpr auto cellValueCondition = std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>;

    template <typename T>
    constexpr auto cellValueProxyCondition = std::is_integral_v<std::decay_t<T>> ||
                                             std::is_floating_point_v<std::decay_t<T>> ||
                                             std::is_constructible_v<std::decay_t<T>, char*> ||
                                             std::is_same_v<std::decay_t<T>, std::string>;

    template <typename T>
    using RowDataProxyConditionType = std::is_base_of<std::bidirectional_iterator_tag, typename std::iterator_traits<typename T::iterator>::iterator_category>;

}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H