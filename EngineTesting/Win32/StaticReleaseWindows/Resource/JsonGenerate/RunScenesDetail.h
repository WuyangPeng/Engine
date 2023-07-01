/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_RUN_SCENES_DETAIL_H
#define JSON_CONFIGURE_RUN_SCENES_DETAIL_H

#include "RunScenes.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::RunScenesContainer::ConstDataSharedPtr JsonConfigure::RunScenesContainer::GetFirstData(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(data, function);

    if (iter != data.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("runScenes表data字段未找到满足条件的配置信息。"s))
}

template <typename Function>
JsonConfigure::RunScenesContainer::DataContainer JsonConfigure::RunScenesContainer::GetData(Function function) const
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
JsonConfigure::RunScenes::Data::ConstBoundsSharedPtr JsonConfigure::RunScenes::Data::GetFirstBounds(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(bounds, function);

    if (iter != bounds.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("runScenes表bounds字段未找到满足条件的配置信息。"s))
}

template <typename Function>
JsonConfigure::RunScenes::Data::BoundsContainer JsonConfigure::RunScenes::Data::GetBounds(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    BoundsContainer result{};

    for (const auto& element : bounds)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::RunScenes::Data::ConstTerrainsSharedPtr JsonConfigure::RunScenes::Data::GetFirstTerrains(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(terrains, function);

    if (iter != terrains.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("runScenes表terrains字段未找到满足条件的配置信息。"s))
}

template <typename Function>
JsonConfigure::RunScenes::Data::TerrainsContainer JsonConfigure::RunScenes::Data::GetTerrains(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    TerrainsContainer result{};

    for (const auto& element : terrains)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_RUN_SCENES_DETAIL_H
