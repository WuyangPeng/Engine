/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:26)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H

#include "Cell.h"
#include "Constants.h"
#include "RowDataProxy.h"
#include "RowDataRange.h"
#include "SimpleCSVException.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"

template <typename T, std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value, T>*>
CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowDataProxy::operator=(const T& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (gMaxColumns < rhs.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, SYSTEM_TEXT("容器大小超过最大列数。"s))
    }

    if (!rhs.empty())
    {
        if constexpr (std::is_same_v<typename T::value_type, CellValue>)
        {
            SetCellValue(rhs);
        }
        else
        {
            SetContainer(rhs);
        }
    }

    return *this;
}

template <typename T, std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value, T>*>
void CoreTools::SimpleCSV::RowDataProxy::SetCellValue(const T& rhs)
{
    auto size = boost::numeric_cast<int>(rhs.size());
    DeleteCellValues(size);

    for (auto value = rhs.rbegin(); value != rhs.rend(); ++value)
    {
        PrependCellValue(*value, size);
        --size;
    }
}

template <typename T, std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<T>::value, T>*>
void CoreTools::SimpleCSV::RowDataProxy::SetContainer(const T& rhs)
{
    RowDataRange range{ GetDocument(), GetRowNode(), 1, boost::numeric_cast<int>(rhs.size()), GetSharedStrings() };

    for (auto target = range.begin();
         const auto& source : rhs)
    {
        if (target == range.end())
        {
            break;
        }

        target->GetValue() = source;

        ++target;
    }
}

template <typename Container, std::enable_if_t<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<Container>::value, Container>*>
CoreTools::SimpleCSV::RowDataProxy::operator Container() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ConvertContainer<Container>();
}

template <typename Container, std::enable_if_t<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> && CoreTools::TextParsing::RowDataProxyConditionType<Container>::value, Container>*>
Container CoreTools::SimpleCSV::RowDataProxy::ConvertContainer() const
{
    Container container{};

    for (auto iter = std::inserter(container, container.end());
         const auto& value : GetValues())
    {
        if constexpr (std::is_same_v<typename Container::value_type, CellValue>)
        {
            *iter++ = value;
        }
        else
        {
            *iter++ = value.Get<typename Container::value_type>();
        }
    }

    return container;
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H
