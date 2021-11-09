///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/07 12:29)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H

#include "CellValueImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
CoreTools::SimpleCSV::CellValueImpl& CoreTools::SimpleCSV::CellValueImpl::operator=(T value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType rhs{ value };

    std::swap(*this, rhs);

    return *this;
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
void CoreTools::SimpleCSV::CellValueImpl::Set(T numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = numberValue;
}

template <typename T,
          typename std::enable_if<std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_constructible_v<T, char*> || std::is_same_v<T, std::string>>::type*>
T CoreTools::SimpleCSV::CellValueImpl::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        if constexpr (std::is_integral_v<T> && std::is_same_v<T, bool>)
        {
            return std::get<bool>(m_Value);
        }
        else if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>)
        {
            return boost::numeric_cast<T>(std::get<int64_t>(m_Value));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return boost::numeric_cast<T>(std::get<double>(m_Value));
        }
        else if constexpr (std::is_same_v<T, std::string> && !std::is_same_v<T, bool>)
        {
            return std::get<std::string>(m_Value);
        }
        else if constexpr (std::is_constructible_v<T, char*> && !std::is_same_v<T, bool>)
        {
            return std::get<std::string>(m_Value).c_str();
        }
    }

    catch (const std::bad_variant_access&)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::ValueType, SYSTEM_TEXT("CellValue 对象不包含请求的类型。"s));
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H
