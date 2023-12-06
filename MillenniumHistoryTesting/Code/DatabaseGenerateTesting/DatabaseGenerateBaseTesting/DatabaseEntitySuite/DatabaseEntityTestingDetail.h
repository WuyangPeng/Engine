/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:37)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"

template <typename KeyType, typename EntityType>
std::map<KeyType, EntityType> DatabaseGenerateBaseTesting::DatabaseEntityTesting::GetEntityContainer(const ResultContainer& database)
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;

    std::map<KeyType, EntityType> container{};

    for (const auto& element : database)
    {
        EntityType entity{ element };

        container.emplace(entity.GetId(), entity);
    }

    return container;
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_DETAIL_H