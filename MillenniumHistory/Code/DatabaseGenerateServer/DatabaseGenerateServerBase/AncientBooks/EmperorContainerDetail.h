/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_EMPEROR_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_EMPEROR_CONTAINER_DETAIL_H

#include "EmperorContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::EmperorContainer::ConstEmperorSharedPtr AncientBooks::EmperorContainer::GetFirstEmperor(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(emperor, function);

    if (iter != emperor.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表未找到满足条件的配置信息。"s))
}

template <typename Function>
AncientBooks::EmperorContainer::Container AncientBooks::EmperorContainer::GetEmperor(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : emperor)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_EMPEROR_CONTAINER_DETAIL_H
