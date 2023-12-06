/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_DETAIL_H

#include "ImperialCourtContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::ImperialCourtContainer::ConstImperialCourtSharedPtr AncientBooks::ImperialCourtContainer::GetFirstImperialCourt(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(imperialCourt, function);
        iter != imperialCourt.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::ImperialCourtContainer::Container AncientBooks::ImperialCourtContainer::GetImperialCourt(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : imperialCourt)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_DETAIL_H
