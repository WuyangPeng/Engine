/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:26)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H

#include "CellValue.h"
#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
CoreTools::SimpleCSV::CellValue& CoreTools::SimpleCSV::CellValue::operator=(T rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType result{ rhs };

    std::swap(*this, result);

    return *this;
}

template <typename T, std::enable_if_t<std::is_same_v<T, CoreTools::SimpleCSV::CellValue> || CoreTools::TextParsing::cellValueCondition<T>>*>
void CoreTools::SimpleCSV::CellValue::Set(T rhs) noexcept(std::is_same_v<T, CellValue>)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = rhs;
}

template <typename T, std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
T CoreTools::SimpleCSV::CellValue::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        if constexpr (std::is_same_v<T, bool>)
        {
            return GetBool();
        }
        else if constexpr (std::is_integral_v<T>)
        {
            return boost::numeric_cast<T>(GetIntegral());
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return boost::numeric_cast<T>(GetDouble());
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return GetString();
        }
        else if constexpr (std::is_constructible_v<T, char*>)
        {
            return GetString().c_str();
        }
    }
    catch (const std::bad_variant_access&)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::ValueType, SYSTEM_TEXT("CellValue 对象不包含请求的类型。"s))
    }
}

template <typename T, std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
CoreTools::SimpleCSV::CellValue::operator T() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return this->Get<T>();
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_DETAIL_H
