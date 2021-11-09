///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/07 12:31)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H

#include "CellValueProxy.h"
#include "Constants.h"
#include "RowDataProxy.h"
#include "SimpleCSVException.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename T,
          typename std::enable_if<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> &&
                                      std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                        typename std::iterator_traits<typename T::iterator>::iterator_category>,
                                  T>::type*>
CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowDataProxy::operator=(const T& values)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (g_MaxColumns < values.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, SYSTEM_TEXT("容器大小超过最大列数。"s));
    }

    if (values.empty())
    {
        return *this;
    }

    if constexpr (std::is_same_v<typename T::value_type, CellValue>)
    {
        auto size = boost::numeric_cast<int>(values.size());
        DeleteCellValues(size);

        for (auto value = values.rbegin(); value != values.rend(); ++value)
        {
            PrependCellValue(*value, size);
            --size;
        }
    }
    else
    {
        RowDataRange range{ GetDocument(), GetRowNode(), 1, boost::numeric_cast<int>(values.size()), GetSharedStrings() };

        auto target = range.begin();
        auto source = values.begin();

        while (true)
        {
            target->GetValue() = *source;
            ++source;
            if (source == values.end() || target == range.end())
            {
                break;
            }

            ++target;
        }
    }

    return *this;
}

template <typename Container,
          typename std::enable_if<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> &&
                                      std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                        typename std::iterator_traits<typename Container::iterator>::iterator_category>,
                                  Container>::type*>
CoreTools::SimpleCSV::RowDataProxy::operator Container() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ConvertContainer<Container>();
}

template <typename Container,
          typename std::enable_if<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> &&
                                      std::is_base_of_v<typename std::bidirectional_iterator_tag,
                                                        typename std::iterator_traits<typename Container::iterator>::iterator_category>,
                                  Container>::type*>
Container CoreTools::SimpleCSV::RowDataProxy::ConvertContainer() const
{
    Container container{};

    auto iter = std::inserter(container, container.end());
    for (const auto& value : GetValues())
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
