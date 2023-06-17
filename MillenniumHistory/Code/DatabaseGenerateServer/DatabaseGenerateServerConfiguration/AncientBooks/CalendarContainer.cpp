/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Calendar.h"
#include "CalendarContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CalendarContainer::CalendarContainer(const CoreTools::CSVContent& csvContent)
    : calendar{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CalendarContainer::Parsing(const CoreTools::CSVContent& csvContent)
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

    const auto iter = std::ranges::unique(calendar, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("calendar������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        calendar.erase(iter.begin(), iter.end());
    }
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
        THROW_EXCEPTION(SYSTEM_TEXT("calendar��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::CalendarContainer::Container AncientBooks::CalendarContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return calendar;
}

