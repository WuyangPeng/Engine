/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_CALENDAR_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_CALENDAR_CONTAINER_DETAIL_H

#include "CalendarContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::CalendarContainer::ConstCalendarSharedPtr AncientBooks::CalendarContainer::GetFirstCalendar(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(calendar, function);
        iter != calendar.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("calendar��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::CalendarContainer::Container AncientBooks::CalendarContainer::GetCalendar(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : calendar)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_CALENDAR_CONTAINER_DETAIL_H