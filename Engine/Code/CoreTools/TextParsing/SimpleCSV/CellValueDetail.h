///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/07 12:29)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H

#include "CellValue.h"
#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "Flags/ValueTypeFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
CoreTools::SimpleCSV::CellValue& CoreTools::SimpleCSV::CellValue::operator=(T value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType result{ value };

    std::swap(*this, result);

    return *this;
}

template <typename T,
          typename std::enable_if<std::is_same_v<T, CoreTools::SimpleCSV::CellValue> || std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
void CoreTools::SimpleCSV::CellValue::Set(T numberValue) noexcept(std::is_same_v<T, CellValue>)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = numberValue;
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
T CoreTools::SimpleCSV::CellValue::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        if constexpr (std::is_integral_v<T> && std::is_same_v<T, bool>)
        {
            return GetBool();
        }
        else if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>)
        {
            return boost::numeric_cast<T>(GetIntegral());
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return boost::numeric_cast<T>(GetDouble());
        }
        else if constexpr (std::is_same_v<T, std::string> && !std::is_same_v<T, bool>)
        {
            return GetString();
        }
        else if constexpr (std::is_constructible_v<T, char*> && !std::is_same_v<T, bool>)
        {
            return GetString().c_str();
        }
    }
    catch (const std::bad_variant_access&)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::ValueType, SYSTEM_TEXT("CellValue 对象不包含请求的类型。"s));
    }
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
CoreTools::SimpleCSV::CellValue::operator T() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return this->Get<T>();
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H
