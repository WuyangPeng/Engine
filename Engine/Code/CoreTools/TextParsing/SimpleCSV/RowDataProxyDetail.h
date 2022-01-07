///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 21:28)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_DETAIL_H

#include "CellValueProxy.h"
#include "Constants.h"
#include "RowDataProxy.h"
#include "SimpleCSVException.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename T,
          typename std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> &&
                                        CoreTools::TextParsing::RowDataProxyConditionType<T>::value,
                                    T>*>
CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowDataProxy::operator=(const T& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (g_MaxColumns < rhs.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, SYSTEM_TEXT("������С�������������"s));
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

template <typename T,
          typename std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> &&
                                        CoreTools::TextParsing::RowDataProxyConditionType<T>::value,
                                    T>*>
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

template <typename T,
          typename std::enable_if_t<!std::is_same_v<T, CoreTools::SimpleCSV::RowDataProxy> &&
                                        CoreTools::TextParsing::RowDataProxyConditionType<T>::value,
                                    T>*>
void CoreTools::SimpleCSV::RowDataProxy::SetContainer(const T& rhs)
{
    RowDataRange range{ GetDocument(), GetRowNode(), 1, boost::numeric_cast<int>(rhs.size()), GetSharedStrings() };

    auto target = range.begin();
    auto source = rhs.begin();

    for (; source != rhs.end() && target != range.end(); ++source, ++target)
    {
        target->GetValue() = *source;
    } 
}

template <typename Container,
          typename std::enable_if_t<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> &&
                                        CoreTools::TextParsing::RowDataProxyConditionType<Container>::value,
                                    Container>*>
CoreTools::SimpleCSV::RowDataProxy::operator Container() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ConvertContainer<Container>();
}

template <typename Container,
          typename std::enable_if_t<!std::is_same_v<Container, CoreTools::SimpleCSV::RowDataProxy> &&
                                        CoreTools::TextParsing::RowDataProxyConditionType<Container>::value,
                                    Container>*>
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
