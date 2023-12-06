/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_YEAR_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_YEAR_CONTAINER_DETAIL_H

#include "YearContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::YearContainer::ConstYearSharedPtr AncientBooks::YearContainer::GetFirstYear(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(year, function);
        iter != year.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("year��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::YearContainer::Container AncientBooks::YearContainer::GetYear(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : year)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_YEAR_CONTAINER_DETAIL_H
