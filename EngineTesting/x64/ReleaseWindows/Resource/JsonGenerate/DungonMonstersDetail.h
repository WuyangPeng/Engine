/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H
#define JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H

#include "DungonMonsters.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::DungonMonstersContainer::ConstDatasSharedPtr JsonConfigure::DungonMonstersContainer::GetFirstDatas(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(datas.cbegin(), datas.cend(), function);

    if (iter != datas.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters表datas字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonMonstersContainer::DatasContainer JsonConfigure::DungonMonstersContainer::GetDatas(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    DatasContainer result{};

    for (const auto& value : datas)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::DungonMonsters::Datas::ConstElementsSharedPtr JsonConfigure::DungonMonsters::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonMonsters::Datas::ElementsContainer JsonConfigure::DungonMonsters::Datas::GetElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ElementsContainer result{};

    for (const auto& value : elements)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H
