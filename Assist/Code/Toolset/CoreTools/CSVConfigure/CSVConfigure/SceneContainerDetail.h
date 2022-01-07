/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H

#include "SceneContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::SceneContainer::ConstSceneSharedPtr CSVConfigure::SceneContainer::GetFirstScene(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    for (const auto& value : scene)
    {
        if (function(value.second))
        {
            return value.second;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("scene表未找到满足条件的配置信息。"s));
}

template <typename Function>
CSVConfigure::SceneContainer::Container CSVConfigure::SceneContainer::GetScene(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : scene)
    {
        if (function(value.second))
        {
            result.emplace_back(value.second);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_SCENE_CONTAINER_DETAIL_H
