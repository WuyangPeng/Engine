///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:37)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H

#include "System/Helper/UserMacro.h"

#include <iterator>
#include <string>
#include <type_traits>

namespace CoreTools
{
    namespace TextParsing
    {
        template <typename T>
        constexpr auto cellValueCondition = std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>;

        template <typename T>
        constexpr auto cellValueProxyCondition = std::is_integral_v<std::decay_t<T>> ||
                                                 std::is_floating_point_v<std::decay_t<T>> ||
                                                 std::is_constructible_v<std::decay_t<T>, char*> ||
                                                 std::is_same_v<std::decay_t<T>, std::string>;

        template <typename T>
        using RowDataProxyConditionType = std::is_base_of<typename std::bidirectional_iterator_tag,
                                                          typename std::iterator_traits<typename T::iterator>::iterator_category>;
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CONDITION_H