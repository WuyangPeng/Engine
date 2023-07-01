/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Calendar.h"
#include "CalendarContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CalendarContainer::CalendarContainer(const CSVContent& csvContent)
    : calendar{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CalendarContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("calendar表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("calendar表结束载入……"));
}

void AncientBooks::CalendarContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        calendar.emplace_back(std::make_shared<Calendar>(csvRow));
    }

    std::ranges::sort(calendar, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::CalendarContainer::Unique()
{
    const auto iter = std::ranges::unique(calendar, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("calendar表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        calendar.erase(iter.begin(), iter.end());
    }

    calendar.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CalendarContainer)

AncientBooks::CalendarContainer::ConstCalendarBaseSharedPtr AncientBooks::CalendarContainer::GetFirstCalendar() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return calendar.at(0);
}

AncientBooks::CalendarContainer::ConstCalendarBaseSharedPtr AncientBooks::CalendarContainer::GetCalendar(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(calendar, std::make_shared<CalendarBase>(key), function);

    if (iter != calendar.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("calendar表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::CalendarContainer::Container AncientBooks::CalendarContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return calendar;
}

