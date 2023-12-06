/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:41)

#include "CategoryEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Category.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CategoryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/CategoryEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::CategoryEntityTesting::CategoryEntityTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer)
    : ParentType{ stream }, categoryContainer{ categoryContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CategoryEntityTesting)

void DatabaseGenerateBaseTesting::CategoryEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::CategoryEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::CategoryEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
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

void DatabaseGenerateBaseTesting::CategoryEntityTesting::SetEntity(CategoryEntity& categoryEntity, const Category& category)
{
    categoryEntity.SetGather(category.GetGather());
    categoryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}

void DatabaseGenerateBaseTesting::CategoryEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Category& category)
{
    const auto database = databaseFlush.SelectOne(CategoryEntity::GetSelect(databaseFlush.GetWrappersStrategy(), category.GetId()),
                                                  CategoryEntity::GetDatabaseFieldContainer());

    auto categoryEntity = CategoryEntity::Create(database, databaseFlush.GetWrappersStrategy(), category.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, categoryEntity, category);

    databaseFlush.ChangeDatabase(category.GetId(), categoryEntity.GetModify());
}

void DatabaseGenerateBaseTesting::CategoryEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Category& category, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(category.GetId());
    auto categoryEntity = result != entityContainer.cend() ? result->second : CategoryEntity{ databaseFlush.GetWrappersStrategy(), category.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, categoryEntity, category);

    databaseFlush.ChangeDatabase(category.GetId(), categoryEntity.GetModify());
}

void DatabaseGenerateBaseTesting::CategoryEntityTesting::EqualTest(const Category& category, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(category.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(category.GetId()));

    const auto& categoryEntity = result->second;

    ASSERT_EQUAL(categoryEntity.GetGather(), category.GetGather());
    ASSERT_EQUAL(categoryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(category.GetCategory()));
}
