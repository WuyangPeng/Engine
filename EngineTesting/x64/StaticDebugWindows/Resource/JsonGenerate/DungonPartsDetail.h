/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef JSON_CONFIGURE_DUNGON_PARTS_DETAIL_H
#define JSON_CONFIGURE_DUNGON_PARTS_DETAIL_H

#include "DungonParts.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::DungonPartsContainer::ConstDatasSharedPtr JsonConfigure::DungonPartsContainer::GetFirstDatas(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(datas.cbegin(), datas.cend(), function);

    if (iter != datas.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表datas字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonPartsContainer::DatasContainer JsonConfigure::DungonPartsContainer::GetDatas(Function function) const
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
JsonConfigure::DungonParts::Datas::ConstScenesSharedPtr JsonConfigure::DungonParts::Datas::GetFirstScenes(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(scenes.cbegin(), scenes.cend(), function);

    if (iter != scenes.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表scenes字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ScenesContainer JsonConfigure::DungonParts::Datas::GetScenes(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ScenesContainer result{};

    for (const auto& value : scenes)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstGroupsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstGroups(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(groups.cbegin(), groups.cend(), function);

    if (iter != groups.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表groups字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::GroupsContainer JsonConfigure::DungonParts::Datas::GetGroups(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    GroupsContainer result{};

    for (const auto& value : groups)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstElementsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::ElementsContainer JsonConfigure::DungonParts::Datas::GetElements(Function function) const
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

template <typename Function>
JsonConfigure::DungonParts::Datas::ConstPassParamsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstPassParams(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(passParams.cbegin(), passParams.cend(), function);

    if (iter != passParams.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表passParams字段未找到满足条件的配置信息。"s));
}

template <typename Function>
JsonConfigure::DungonParts::Datas::PassParamsContainer JsonConfigure::DungonParts::Datas::GetPassParams(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    PassParamsContainer result{};

    for (const auto& value : passParams)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_DUNGON_PARTS_DETAIL_H
