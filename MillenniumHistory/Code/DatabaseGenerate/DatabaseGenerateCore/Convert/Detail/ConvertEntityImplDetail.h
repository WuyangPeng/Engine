/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:30)

#ifndef DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_IMPL_DETAIL_H
#define DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_IMPL_DETAIL_H

#include "ConvertEntityImpl.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

template <typename KeyType, typename EntityType>
std::map<KeyType, EntityType> DatabaseGenerateCore::ConvertEntityImpl::GetEntityContainer(const ResultContainer& database)
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

template <typename EntityContainerType>
void DatabaseGenerateCore::ConvertEntityImpl::DeleteInvalidDatabase(const EntityContainerType& entityContainer)
{
    DATABASE_GENERATE_CORE_CLASS_IS_VALID_1;

    for (const auto& [key, entity] : entityContainer)
    {
        databaseFlush->ChangeDatabase(entity.GetId(), entity.GetDelete());
    }
}

#endif  // DATABASE_GENERATE_CORE_CONVERT_CONVERT_ENTITY_IMPL_DETAIL_H