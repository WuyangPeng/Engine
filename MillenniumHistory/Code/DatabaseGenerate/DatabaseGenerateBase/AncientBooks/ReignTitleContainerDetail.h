/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_DETAIL_H

#include "ReignTitleContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::ReignTitleContainer::ConstReignTitleSharedPtr AncientBooks::ReignTitleContainer::GetFirstReignTitle(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(reignTitle, function);
        iter != reignTitle.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表未找到满足条件的配置信息。"s))
}

template <typename Function>
AncientBooks::ReignTitleContainer::Container AncientBooks::ReignTitleContainer::GetReignTitle(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : reignTitle)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_DETAIL_H
