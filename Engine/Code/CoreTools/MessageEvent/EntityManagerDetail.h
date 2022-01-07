///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/25 20:14)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H

#include "EntityManager.h"

template <typename EntityType, typename ResultType, typename... Args>
std::shared_ptr<ResultType> CoreTools::EntityManager::MakeEntity(Args&&... args)
{
    auto result = std::make_shared<EntityType>(std::forward<Args>(args)...);

    result->Register();

    return result;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_DETAIL_H