/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_DETAIL_H

#include "SexagenaryCycleContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::SexagenaryCycleContainer::ConstSexagenaryCycleBaseSharedPtr AncientBooks::SexagenaryCycleContainer::GetFirstSexagenaryCycle(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(sexagenaryCycle, function);

    if (iter != sexagenaryCycle.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle表未找到满足条件的配置信息。"s))
}

template <typename Function>
AncientBooks::SexagenaryCycleContainer::Container AncientBooks::SexagenaryCycleContainer::GetSexagenaryCycle(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : sexagenaryCycle)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_SEXAGENARY_CYCLE_CONTAINER_DETAIL_H
