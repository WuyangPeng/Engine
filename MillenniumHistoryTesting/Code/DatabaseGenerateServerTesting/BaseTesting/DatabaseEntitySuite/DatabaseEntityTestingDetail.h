///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 22:20)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"

template <typename KeyType, typename EntityType>
std::map<KeyType, EntityType> DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::GetEntityContainer(const ResultContainer& database)
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;

    std::map<KeyType, EntityType> container{};

    for (const auto& element : database)
    {
        EntityType entity{ element };

        container.emplace(entity.GetId(), entity);
    }

    return container;
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H