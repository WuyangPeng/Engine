///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 21:27)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H

#include "CellValueImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

template <typename T, typename std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
CoreTools::SimpleCSV::CellValueImpl& CoreTools::SimpleCSV::CellValueImpl::operator=(T rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType result{ rhs };

    std::swap(*this, result);

    return *this;
}

template <typename T, typename std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
void CoreTools::SimpleCSV::CellValueImpl::Set(T rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *this = rhs;
}

template <typename T, typename std::enable_if_t<CoreTools::TextParsing::cellValueCondition<T>>*>
T CoreTools::SimpleCSV::CellValueImpl::Get() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        if constexpr (std::is_same_v<T, bool>)
        {
            return std::get<bool>(m_Value);
        }
        else if constexpr (std::is_integral_v<T>)
        {
            return boost::numeric_cast<T>(std::get<int64_t>(m_Value));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return boost::numeric_cast<T>(std::get<double>(m_Value));
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return std::get<std::string>(m_Value);
        }
        else if constexpr (std::is_constructible_v<T, char*>)
        {
            return std::get<std::string>(m_Value).c_str();
        }
    }
    catch (const std::bad_variant_access&)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::ValueType, SYSTEM_TEXT("CellValue ���󲻰�����������͡�"s));
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_CELL_VALUE_IMPL_DETAIL_H
