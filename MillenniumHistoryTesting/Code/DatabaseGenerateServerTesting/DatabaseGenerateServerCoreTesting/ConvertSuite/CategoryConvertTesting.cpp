///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 23:04)

#include "CategoryConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Category.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CategoryEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::CategoryConvertTesting::CategoryConvertTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer)
    : ParentType{ stream }, categoryContainer{ categoryContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, CategoryConvertTesting)

void DatabaseGenerateServerCoreTesting::CategoryConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& category : categoryContainer.GetContainer())
    {
        const auto categoryEntity = convertEntity.Convert(*category);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *category, categoryEntity);
    }
}

void DatabaseGenerateServerCoreTesting::CategoryConvertTesting::EqualTest(const Category& category, const CategoryEntity& categoryEntity)
{
    ASSERT_EQUAL(categoryEntity.GetGather(), category.GetGather());
    ASSERT_EQUAL(categoryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}
