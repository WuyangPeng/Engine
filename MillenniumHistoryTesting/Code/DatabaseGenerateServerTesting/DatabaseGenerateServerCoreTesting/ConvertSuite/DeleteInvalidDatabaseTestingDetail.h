///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 22:18)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "DeleteInvalidDatabaseTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void DatabaseGenerateServerCoreTesting::DeleteInvalidDatabaseTesting::DatabaseSave(ConvertEntity& convertEntity, const T& container)
{
    for (const auto& element : container.GetContainer())
    {
        const auto entity = convertEntity.Convert(*element);

        ASSERT_EQUAL(entity.GetId(), element->GetId());
    }
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H