//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:39)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H

#include "EntityManager.h"

template <typename EntityType, typename ResultType, typename... Args>
std::shared_ptr<ResultType> CoreTools::EntityManager::MakeEntity(Args&&... args)
{
    auto result = std::make_shared<EntityType>(args...);

    result->Register();

    return result;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H