/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_MONSTERS_DETAIL_H
#define JSON_CONFIGURE_MONSTERS_DETAIL_H

#include "Monsters.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::MonstersContainer::ConstDataSharedPtr JsonConfigure::MonstersContainer::GetFirstData(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(data, function);

    if (iter != data.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("monsters表data字段未找到满足条件的配置信息。"s))
}

template <typename Function>
JsonConfigure::MonstersContainer::DataContainer JsonConfigure::MonstersContainer::GetData(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    DataContainer result{};

    for (const auto& element : data)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::Monsters::Data::ConstElementsSharedPtr JsonConfigure::Monsters::Data::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(elements, function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("monsters表elements字段未找到满足条件的配置信息。"s))
}

template <typename Function>
JsonConfigure::Monsters::Data::ElementsContainer JsonConfigure::Monsters::Data::GetElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ElementsContainer result{};

    for (const auto& element : elements)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_MONSTERS_DETAIL_H
