///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/07 12:29)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValueProxy.h"
#include "Flags/ValueTypeFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, const char*> || std::is_same_v<T, std::string> || std::is_same_v<T, CoreTools::SimpleCSV::CellValue>>::type*>
CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::CellValueProxy::operator=(T value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if constexpr (std::is_integral_v<T> && std::is_same_v<T, bool>)
    {
        SetBoolean(value);
    }
    else if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>)
    {
        SetInteger(value);
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        SetFloat(value);
    }
    else if constexpr (std::is_same_v<T, std::string> && !std::is_same_v<T, bool> && !std::is_same_v<T, CellValue>)
    {
        SetString(value);
    }
    else if constexpr (std::is_constructible_v<T, const char*> && !std::is_same_v<T, bool> && !std::is_same_v<T, CellValue>)
    {
        if constexpr (std::is_same<const char*, typename std::remove_reference<typename std::remove_cv<T>::type>::type>::value)
        {
            SetString(value);
        }
        else if constexpr (std::is_same<std::string_view, T>::value)
        {
            SetString(std::string{ value });
        }
        else
        {
            SetString(value);
        }
    }
    else if constexpr (std::is_same_v<T, CellValue>)
    {
        switch (value.GetType())
        {
            case ValueType::Boolean:
            {
                SetBoolean(value.template Get<bool>());
                break;
            }
            case ValueType::Integer:
            {
                SetInteger(value.template Get<int64_t>());
                break;
            }
            case ValueType::Float:
            {
                SetFloat(value.template Get<double>());
                break;
            }
            case ValueType::String:
            {
                SetString(value.template Get<std::string>());
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return *this;
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, const char*> || std::is_same_v<T, std::string> || std::is_same_v<T, CoreTools::SimpleCSV::CellValue>>::type*>
void CoreTools::SimpleCSV::CellValueProxy::Set(T value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = value;
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
T CoreTools::SimpleCSV::CellValueProxy::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValue().Get<T>();
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_DETAIL_H
