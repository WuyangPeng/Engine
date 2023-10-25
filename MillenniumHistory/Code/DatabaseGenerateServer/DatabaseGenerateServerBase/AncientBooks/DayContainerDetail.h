/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_DAY_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_DAY_CONTAINER_DETAIL_H

#include "DayContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::DayContainer::ConstDaySharedPtr AncientBooks::DayContainer::GetFirstDay(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(day, function);

    if (iter != day.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("day��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::DayContainer::Container AncientBooks::DayContainer::GetDay(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : day)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_DAY_CONTAINER_DETAIL_H
