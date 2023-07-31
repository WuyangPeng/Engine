///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "CategoryEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Category.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CategoryEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CategoryEntityTesting::CategoryEntityTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer)
    : ParentType{ stream }, categoryContainer{ categoryContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CategoryEntityTesting)

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& category : categoryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *category);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CategoryEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CategoryEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, CategoryEntity>(database);

    for (const auto& category : categoryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *category, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CategoryEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CategoryEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), categoryContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, CategoryEntity>(database);

    for (const auto& category : categoryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *category, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::SetEntity(CategoryEntity& categoryEntity, const Category& category)
{
    categoryEntity.SetGather(category.GetGather());
    categoryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Category& category)
{
    const auto database = databaseFlush.SelectOne(CategoryEntity::GetSelect(databaseFlush.GetWrappersStrategy(), category.GetId()),
                                                  CategoryEntity::GetDatabaseFieldContainer());

    auto categoryEntity = CategoryEntity::Create(database, databaseFlush.GetWrappersStrategy(), category.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, categoryEntity, category);

    databaseFlush.ChangeDatabase(category.GetId(), categoryEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Category& category, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(category.GetId());
    auto categoryEntity = result != entityContainer.cend() ? result->second : CategoryEntity{ databaseFlush.GetWrappersStrategy(), category.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, categoryEntity, category);

    databaseFlush.ChangeDatabase(category.GetId(), categoryEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CategoryEntityTesting::EqualTest(const Category& category, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(category.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(category.GetId()));

    const auto& categoryEntity = result->second;

    ASSERT_EQUAL(categoryEntity.GetGather(), category.GetGather());
    ASSERT_EQUAL(categoryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}
