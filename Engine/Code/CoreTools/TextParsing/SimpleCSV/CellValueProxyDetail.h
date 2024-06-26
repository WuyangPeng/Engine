/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 11:24)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValueProxy.h"
#include "Flags/ValueTypeFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
requires(CoreTools::TextParsing::cellValueProxyCondition<T> || std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>)
CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellValueProxy::operator=(T&& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using DecayType = std::decay_t<T>;

    if constexpr (std::is_same_v<DecayType, bool>)
    {
        SetBoolean(std::forward<T>(rhs));
    }
    else if constexpr (std::is_integral_v<DecayType>)
    {
        SetInteger(std::forward<T>(rhs));
    }
    else if constexpr (std::is_floating_point_v<DecayType>)
    {
        SetFloat(std::forward<T>(rhs));
    }
    else if constexpr (std::is_same_v<DecayType, CellValue>)
    {
        SetCellValue(std::forward<T>(rhs));
    }
    else if constexpr (std::is_same_v<DecayType, std::string>)
    {
        SetString(std::forward<T>(rhs));
    }
    else if constexpr (std::is_same_v<DecayType, std::string_view>)
    {
        SetString(std::string{ std::forward<T>(rhs) });
    }
    else if constexpr (std::is_constructible_v<DecayType, char*>)
    {
        SetString(rhs);
    }

    return *this;
}

template <typename T>
requires(CoreTools::TextParsing::cellValueProxyCondition<T> || std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>)
void CoreTools::SimpleCSV::CellValueProxy::Set(T&& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = std::forward<T>(rhs);
}

template <typename T>
requires(CoreTools::TextParsing::cellValueProxyCondition<T>)
T CoreTools::SimpleCSV::CellValueProxy::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValue().Get<T>();
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H
