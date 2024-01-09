/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:24)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Month.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/MonthEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "MonthEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::MonthEntityTesting::MonthEntityTesting(const OStreamShared& stream, MonthContainer monthContainer)
    : ParentType{ stream }, monthContainer{ std::move(monthContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, MonthEntityTesting)

void DatabaseGenerateBaseTesting::MonthEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& month : monthContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *month);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(MonthEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  MonthEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, MonthEntity>(database);

    for (const auto& month : monthContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *month, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(MonthEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  MonthEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), monthContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, MonthEntity>(database);

    for (const auto& month : monthContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *month, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::SetEntity(MonthEntity& monthEntity, const Month& month)
{
    monthEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Month& month)
{
    const auto database = databaseFlush.SelectOne(MonthEntity::GetSelect(databaseFlush.GetWrappersStrategy(), month.GetId()),
                                                  MonthEntity::GetDatabaseFieldContainer());

    auto monthEntity = MonthEntity::Create(database, databaseFlush.GetWrappersStrategy(), month.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, monthEntity, month);

    databaseFlush.ChangeDatabase(month.GetId(), monthEntity.GetModify());
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Month& month, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(month.GetId());
    auto monthEntity = result != entityContainer.cend() ? result->second : MonthEntity{ databaseFlush.GetWrappersStrategy(), month.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, monthEntity, month);

    databaseFlush.ChangeDatabase(month.GetId(), monthEntity.GetModify());
}

void DatabaseGenerateBaseTesting::MonthEntityTesting::EqualTest(const Month& month, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(month.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(month.GetId()));

    const auto& monthEntity = result->second;

    ASSERT_EQUAL(monthEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(month.GetName()));
}
