/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:48)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H

#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DeleteInvalidDatabaseTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void DatabaseGenerateCoreTesting::DeleteInvalidDatabaseTesting::DatabaseSave(ConvertEntity& convertEntity, const T& container)
{
    for (const auto& element : container.GetContainer())
    {
        const auto entity = convertEntity.Convert(*element);

        ASSERT_EQUAL(entity.GetId(), element->GetId());
    }
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_DETAIL_H